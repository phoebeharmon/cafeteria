//
//  userprocessor.cpp
//  fantastic-finale-phoebeharmon
//
//  Created by Phoebe Harmon on 12/3/19.
//

#include "userprocessor.hpp"
/*
void UserProcessor::GetUserInput() {
    std::cout << "Choose a number to see dish options.\n";
    std::cout << "1 - Breakfast\t2 - Lunch\t3 - Dinner\n";
    std::cout << "Enter '0' when finished.\n";
    
    int meal_choice;
    std::cin >> meal_choice;
        
    while (meal_choice != 0) {
        if (CheckValidMeal(meal_choice)) {
            std::vector<Item> dishes = GetDishes(meal_choice);
            for (Item dish : dishes) {
                std::cout << dish.formal_name << "\n";
            }
            
            RequestFavoriteDishes(dishes);
            std::cout << "\nYour current list of favorites:\n";
            for (Item dish : favorite_dishes) {
                std::cout << dish.formal_name << "\n";
            }
        }
        else {
            std::cout << "Error with meal input. Try again.\n";
            std::cout << "1 - Breakfast\t2 - Lunch\t3 - Dinner\t0 - Quit\n";
        }
        
        std::cout << "1 - Breakfast\t2 - Lunch\t3 - Dinner\t0 - Quit\n";
        std::cin >> meal_choice;
    }
    
    std::cout << "\nYour final list of favorites:\n";
    for (Item dish : favorite_dishes) {
        std::cout << dish.formal_name << "\n";
    }
}
*/
void UserProcessor::GetUserInput() {
    std::cout << "All dish options:\n";
        
    GetDishes(0);
    SaveItemsToFile();
    for (Item dish : items_unique) {
        std::cout << dish.formal_name << "\n";
    }
    
    RequestFavoriteDishes(items_unique);
    std::cout << "\nYour current list of favorites:\n";
    for (Item dish : favorite_dishes) {
        std::cout << dish.formal_name << "\n";
    }

    std::cout << "\nYour final list of favorites:\n";
    for (Item dish : favorite_dishes) {
        std::cout << dish.formal_name << "\n";
    }
}

void UserProcessor::RequestFavoriteDishes(std::vector<Item> dishes) {
    std::cout << "\nEnter the names of your favorite dishes.\nEnter 'done' when done." << std::endl;
    std::string dish_choice;
    // Get rid of extra whitespace when switching to std::getline from std::cin
    std::getline(std::cin >> std::ws, dish_choice);
    //dish_choice = ofSystemTextBoxDialog("Enter dish: ");


    while (dish_choice != "done") {
        if ((CheckValidDish(dish_choice, dishes) && (!CheckValidDish(dish_choice, favorite_dishes)))) {
            favorite_dishes.push_back(GetItem(dish_choice, dishes));
        }
        else {
            std::cout << "Error with input. Try again.\n";
        }
        
        std::getline(std::cin, dish_choice);
        //dish_choice = ofSystemTextBoxDialog("Enter dish: ");

    }
}

Item UserProcessor::GetItem(std::string dish, std::vector<Item> dishes) {
    for (Item element : dishes) {
        if (element.formal_name == dish) {
            return element;
        }
    }
}

// check that it's in dishes, check that it's not already in favorite_dishes
bool UserProcessor::CheckValidDish(std::string dish, std::vector<Item> dishes) {
    /*if (dishes.empty()) {
        return true;
    }*/
    
    for (Item element : dishes) {
        if (element.formal_name == dish) {
            return true;
        }
    }
    
    return false;
}

std::vector<Item> UserProcessor::GetDishes(int meal) {
    DataProcessor processor;
    DateCalculator calculator;
    std::vector<std::string> dates = calculator.GetWeekDatesVector();
    std::cout << "\nLoading";
    
    for (int day = 0; day < 7; day++) {
        for (int hall_id = 1; hall_id <= kNumOfDiningHalls; hall_id++) {
            std::string hall_id_string = std::to_string(hall_id);
            std::string url_string = processor.BuildUrlDay(hall_id_string, dates.at(day));
            std::string url_content = processor.ReadUrl(url_string);

            //std::cout << ".";
            std::cout << ".";
            if (!url_content.empty()) {
                nlohmann::json json_object = processor.ConvertStringToJson(url_content);
                std::vector<Item> temp_items = processor.ConvertJsonToItems(json_object);
                
                for (Item dish : temp_items) {
                    items_repeat.push_back(dish);
                }
            }
        }
    }
    
    //std::vector<std::string> meal_name = meal_id.at(meal);
    //std::vector<Item> menu;
    
    // Check for meal type and duplicates
    /*for (Item dish : items_repeat) {
        if (CheckValidDishForMeal(dish.meal, meal_name) && !CheckValidDish(dish.formal_name, menu)) {
            menu.push_back(dish);
        }
    }*/
    
    for (Item dish : items_repeat) {
        if (!CheckValidDish(dish.formal_name, items_unique)) {
            items_unique.push_back(dish);
        }
    }
    
    return items_unique;
}

// check that the dish is in the meal
bool UserProcessor::CheckValidDishForMeal(std::string meal_name, std::vector<std::string> meals) {
    for (std::string meal : meals) {
        if (meal == meal_name) {
            return true;
        }
    }
    
    return false;
}

bool UserProcessor::CheckValidMeal(int meal) {
    return (meal == 1 || meal == 2 || meal == 3);
}

std::vector<Item> UserProcessor::GetFavoriteDishes() {
    return favorite_dishes;
}

void UserProcessor::SaveItemsToFile() {
    DateCalculator calculator;
    std::string date = calculator.ConvertDateVectorToString(calculator.GetCurrentDate());
    std::ofstream file;
    std::string file_name = "/Users/phoebeharmon/Documents/of_v20191112_osx_release/apps/myApps/fantastic-finale-phoebeharmon/fantastic-finale-phoebeharmon/src/items.txt";
    file.open(file_name);
    
    for (Item dish : items_unique) {
        file << dish.formal_name << "\n";
        file << dish.course << "\n";
        file << dish.meal << "\n";
        file << dish.ingredients << "\n";
        file << dish.date << "\n";
        file << std::to_string(dish.item_id) << "\n";
        file << std::to_string(dish.dining_hall_id) << "\n";
    }
    
    file.close();
}

void UserProcessor::SaveFavoritesToFile() {
    
}
