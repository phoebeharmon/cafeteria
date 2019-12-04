//
//  userprocessor.cpp
//  fantastic-finale-phoebeharmon
//
//  Created by Phoebe Harmon on 12/3/19.
//

#include "userprocessor.hpp"
#include "dataprocessor.hpp"
#include <iostream>

void UserProcessor::GetUserInput() {
   std::cout << "Choose a number to see dish options.\n";
    std::cout << "1 - Breakfast\t2 - Lunch\t3 - Dinner\n";
    
    int meal_choice;
    std::cin >> meal_choice;
    
    while (!CheckValidMeal(meal_choice)) {
        std::cout << "Error with input. Try again.\n";
        std::cout << "Choose a meal to see dish options.\n";
        std::cout << "Breakfast\tLunch\tDinner\n";
        std::cin >> meal_choice;
    }
    
    std::cout << DisplayDishes(meal_choice);
}

std::string UserProcessor::DisplayDishes(int meal) {
    DataProcessor processor;
    std::string hall_id = "1";
    std::string url_string = processor.BuildUrl(hall_id);
    std::string url_content = processor.ReadUrl(url_string);
    nlohmann::json json_object = processor.ConvertStringToJson(url_content);
    std::vector<Item> items = processor.ConvertJsonToItems(json_object);
    
    std::vector<std::string> meal_name = meal_id.at(meal);
    std::vector<std::string> menu;
    std::string menu_string;
    
    // Check for meal type and duplicates
    for (Item element : items) {
        if (std::count(meal_name.begin(), meal_name.end(), element.meal)
            && !std::count(menu.begin(), menu.end(), element.formal_name)) {
            menu.push_back(element.formal_name);
        }
    }
    
    for (std::string dish : menu) {
        menu_string.append(dish);
        menu_string.append("\n");
    }
    
    return menu_string;
}

bool UserProcessor::CheckValidMeal(int meal) {
    return (meal == 1 || meal == 2 || meal == 3);
}
