//
//  userprocessor.cpp
//  fantastic-finale-phoebeharmon
//
//  Created by Phoebe Harmon on 12/3/19.
//

#include "userprocessor.hpp"

void UserProcessor::GetUserInput() {
    std::cout << "Choose a number to see dish options.\n";
    std::cout << "1 - Breakfast\t2 - Lunch\t3 - Dinner\n";
    std::cout << "Enter '0' when finished.\n";
    
    int meal_choice;
    std::cin >> meal_choice;
    
    while (meal_choice != 0) {
        if (CheckValidMeal(meal_choice)) {
            std::vector<std::string> dishes = GetDishes(meal_choice);
            for (std::string dish : dishes) {
                std::cout << dish << "\n";
            }
            
            GetFavoriteDishes(dishes);
            std::cout << "\nYour current list of favorites:\n";
            for (std::string dish : favorite_dishes) {
                std::cout << dish << "\n";
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
    for (std::string dish : favorite_dishes) {
        std::cout << dish << "\n";
    }
}

void UserProcessor::GetFavoriteDishes(std::vector<std::string> dishes) {
    std::cout << "\nEnter the names of your favorite dishes.\nEnter 'done' when done.\n";
    std::string dish_choice;
    std::getline(std::cin, dish_choice);

    while (dish_choice != "done") {
        if (CheckValidDish(dish_choice, dishes)) {
            favorite_dishes.push_back(dish_choice);
        }
        else {
            std::cout << "Error with input. Try again.\n";
        }
        
        std::getline(std::cin, dish_choice);
    }
}

bool UserProcessor::CheckValidDish(std::string dish, std::vector<std::string> dishes) {
    if (favorite_dishes.size() == 0) {
        return true;
    }
    else {
        return (std::count(dishes.begin(), dishes.end(), dish)
            && !std::count(favorite_dishes.begin(), favorite_dishes.end(), dish));
    }
}

std::vector<std::string> UserProcessor::GetDishes(int meal) {
    DataProcessor processor;
    std::string hall_id = "1";
    std::string url_string = processor.BuildUrl(hall_id);
    std::string url_content = processor.ReadUrl(url_string);
    nlohmann::json json_object = processor.ConvertStringToJson(url_content);
    items = processor.ConvertJsonToItems(json_object);
    
    std::vector<std::string> meal_name = meal_id.at(meal);
    std::vector<std::string> menu;
    
    // Check for meal type and duplicates
    for (Item element : items) {
        if (std::count(meal_name.begin(), meal_name.end(), element.meal)
            && !std::count(menu.begin(), menu.end(), element.formal_name)) {
            menu.push_back(element.formal_name);
        }
    }
    
    return menu;
}

bool UserProcessor::CheckValidMeal(int meal) {
    return (meal == 1 || meal == 2 || meal == 3);
}
