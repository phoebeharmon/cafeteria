//
//  userprocessor.cpp
//  fantastic-finale-phoebeharmon
//
//  Created by Phoebe Harmon on 12/3/19.
//

#include "userprocessor.hpp"
void UserProcessor::HandleUserInput() {
    std::cout << "All dish options:\n";
        
    items_unique = LoadItemsFile();
    SaveItemsToFile();
    
    for (Item dish : items_unique) {
        std::cout << dish.formal_name << "\n";
    }
    
    LoadFavoritesFile();
}

void UserProcessor::RequestFavoriteDishes(std::vector<Item> dishes) {
    std::cout << "\nEnter the names of your favorite dishes.\nEnter 'done' when done." << std::endl;
    std::string dish_choice;
    // Get rid of extra whitespace for switching to std::getline from std::cin
    std::getline(std::cin >> std::ws, dish_choice);

    // Add to favorite_dishes if the dish is an item on the menu and not already in favorite_dishes
    while (dish_choice != "done") {
        if ((CheckValidDish(dish_choice, dishes) && (!CheckValidDish(dish_choice, favorite_dishes)))) {
            favorite_dishes.push_back(GetItem(dish_choice, dishes));
        }
        else {
            std::cout << "Error with input. Try again.\n";
        }
        
        std::getline(std::cin, dish_choice);
    }
    
    SaveFavoritesToFile();
}

Item UserProcessor::GetItem(std::string dish, std::vector<Item> dishes) {
    for (Item element : dishes) {
        if (element.formal_name == dish) {
            return element;
        }
    }
}

bool UserProcessor::CheckValidDish(std::string dish, std::vector<Item> dishes) {
    for (Item element : dishes) {
        if (element.formal_name == dish) {
            return true;
        }
    }
    
    return false;
}

std::vector<Item> UserProcessor::GetDishes() {
    DataProcessor processor;
    DateCalculator calculator;
    std::vector<std::string> dates = calculator.GetWeekDatesVector();
    std::cout << "\nLoading...\n";
    
    // Build a URL for each day and each dining hall
    for (int day = 0; day < 7; day++) {
        for (int hall_id = 1; hall_id <= kNumOfDiningHalls; hall_id++) {
            // Convert URL to vector of Item objects
            std::string hall_id_string = std::to_string(hall_id);
            std::string url_string = processor.BuildUrlDay(hall_id_string, dates.at(day));
            std::string url_content = processor.ReadUrl(url_string);

            // Ignore dining halls that aren't serving food that day
            if (!url_content.empty()) {
                nlohmann::json json_object = processor.ConvertStringToJson(url_content);
                std::vector<Item> temp_items = processor.ConvertJsonToItems(json_object);
                
                // Create a vector where items all have unique names
                for (Item dish : temp_items) {
                    if (!CheckValidDish(dish.formal_name, items_unique)) {
                        items_unique.push_back(dish);
                    }
                }
            }
        }
    }
    
    // Sort vector alphabetically by name
    std::vector<Item> items_unique_copy = items_unique;
    std::sort(items_unique_copy.begin(), items_unique_copy.end());

    return items_unique_copy;
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
    
    // Write attributes of Item objects to each line of file
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
    std::ofstream file;
    std::string file_name = "/Users/phoebeharmon/Documents/of_v20191112_osx_release/apps/myApps/fantastic-finale-phoebeharmon/fantastic-finale-phoebeharmon/src/favorites.txt";
    file.open(file_name);
    
    // Write attributes of Item objects to each line of file
    for (Item dish : favorite_dishes) {
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

std::vector<Item> UserProcessor::LoadItemsFile() {
    std::string line;
    std::ifstream file;
        
    std::vector<Item> file_contents;
    int line_count = 0;
    file.open(
            "/Users/phoebeharmon/Documents/of_v20191112_osx_release/apps/myApps/fantastic-finale-phoebeharmon/fantastic-finale-phoebeharmon/src/items.txt");

    if (!file) {
        file_contents = GetDishes();
    }
    else {
        // Runs if there is still lines left in file
        while(!file.eof()) {
            // Builds Item objects
            Item item;
            
            getline(file, line);
            item.formal_name = line;
            
            getline(file, line);
            item.course = line;
            
            getline(file, line);
            item.meal = line;
            
            getline(file, line);
            item.ingredients = line;
            
            getline(file, line);
            item.date = line;
            
            getline(file, line);
            std::string id_string = line;
            std::stringstream stream(id_string);
            int id = 0;
            stream >> id;
            item.item_id = id;
            
            getline(file, line);
            std::string hall_string = line;
            std::stringstream stream_two(hall_string);
            int hall_id = 0;
            stream_two >> hall_id;
            item.dining_hall_id = hall_id;
            
            file_contents.push_back(item);
        }
    }
    
    file.close();

    return file_contents;
}


void UserProcessor::LoadFavoritesFile() {
    std::string line;
    std::ifstream file;
        
    std::vector<Item> file_contents;
    int line_count = 0;
    file.open(
        "/Users/phoebeharmon/Documents/of_v20191112_osx_release/apps/myApps/fantastic-finale-phoebeharmon/fantastic-finale-phoebeharmon/src/favorites.txt");

    if (!file) {
        RequestFavoriteDishes(items_unique);
    }
    else {
        // User chooses whether to load favorites file
        int choice;
        std::cout << "You have saved favorites. Enter '0' to use your saved favorites. Enter '1' to choose new favorites.\n";
        std::cin >> choice;
        while (choice != 0 && choice != 1) {
            std::cout << "Choose '0' or '1'\n";
            std::cin >> choice;
        }
        
        if (choice == 1) {
            RequestFavoriteDishes(items_unique);
        }
        else {
            // Runs if there is still lines left in file
            while(!file.eof()) {
                // Builds Item objects
                Item item;
                
                getline(file, line);
                item.formal_name = line;
                
                getline(file, line);
                item.course = line;
                
                getline(file, line);
                item.meal = line;
                
                getline(file, line);
                item.ingredients = line;
                
                getline(file, line);
                item.date = line;
                
                getline(file, line);
                std::string id_string = line;
                std::stringstream stream(id_string);
                int id = 0;
                stream >> id;
                item.item_id = id;
                
                getline(file, line);
                std::string hall_string = line;
                std::stringstream stream_two(hall_string);
                int hall_id = 0;
                stream_two >> hall_id;
                item.dining_hall_id = hall_id;
                
                file_contents.push_back(item);
            }
            
            favorite_dishes = file_contents;
        }
    }
    
    file.close();
}
