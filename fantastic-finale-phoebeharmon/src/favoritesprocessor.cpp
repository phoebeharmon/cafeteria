//
//  favoritesprocessor.cpp
//  fantastic-finale-phoebeharmon
//
//  Created by Phoebe Harmon on 12/10/19.
//

#include "favoritesprocessor.hpp"

std::vector<Item> FavoritesProcessor::GetFutureMenu() {
    DataProcessor processor;
    std::vector<Item> menu;
    DateCalculator calculator;
    std::vector<std::string> dates = calculator.GetWeekLaterDatesVector();
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
                std::vector<Item> temp_menu = processor.ConvertJsonToItems(json_object);
                
                for (Item dish : temp_menu) {
                    menu.push_back(dish);
                }
            }
        }
    }

    return menu;
}

std::map<int, std::vector<Item>> FavoritesProcessor::FindFavoritesInFutureMenu(std::vector<Item> menu, std::vector<Item> favorites) {
   // Initialize map
    std::map<int, std::vector<Item>> favorites_serving_info;
    for (Item dish : favorites) {
        favorites_serving_info.insert({dish.item_id, {}});
    }
    
    // Add items to favorites_serving_info if they have the same ID as a favorite dish
    for (Item menu_dish : menu) {
        for (Item favorite_dish : favorites) {
            if (menu_dish.item_id == favorite_dish.item_id) {
                favorites_serving_info.at(menu_dish.item_id).push_back(menu_dish);
            }
        }
    }

    return favorites_serving_info;
}

std::string FavoritesProcessor::GetChart(std::map<int, std::vector<Item>> serving_info) {
    std::string chart;
    std::map<int, std::vector<Item>>::iterator it;
    
    // Create string to display serving info (name of dish, date, location)
    for (it = serving_info.begin(); it != serving_info.end(); it++)
    {
        int item_id = it->first;
        std::vector<Item> dishes = it->second;
        if (!dishes.empty()) {
            chart.append("\n\n" + dishes.at(0).formal_name + "\n");
            
            for (Item serving : dishes) {
                chart.append(serving.date + "\t" + dining_hall_ids.at(serving.dining_hall_id) + "\t" + serving.meal + "\n");
            }
        }
    }

    return chart;
}
