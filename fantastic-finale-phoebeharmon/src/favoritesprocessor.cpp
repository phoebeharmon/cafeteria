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
    
    for (int hall_id = 0; hall_id <= kNumOfDiningHalls; hall_id++) {
        std::string hall_id_string = std::to_string(hall_id);
        std::string url_string = processor.BuildUrlWeekTwo(hall_id_string);
        std::string url_content = processor.ReadUrl(url_string);
        nlohmann::json json_object = processor.ConvertStringToJson(url_content);
        std::vector<Item> temp_menu = processor.ConvertJsonToItems(json_object);
        
        for (Item dish : temp_menu) {
            menu.push_back(dish);
        }
    }
    
    return menu;
}

std::map<int, std::map<std::string, Item>> FavoritesProcessor::FindFavoritesInFutureMenu(std::vector<Item> menu) {
    UserProcessor user_processor;
    std::vector<Item> favorites = user_processor.GetFavoriteDishes();
    DateCalculator date_calculator;
    std::string date = date_calculator.ConvertDateVectorToString(date_calculator.GetCurrentDate());
    
    // Initialize map
    std::map<int, std::map<std::string, Item>> favorites_serving_info;
    for (Item dish : favorites) {
        favorites_serving_info.insert({dish.item_id, {}});
    }
    
    for (Item menu_dish : menu) {
        for (Item favorite_dish : favorites) {
            if (menu_dish.item_id == favorite_dish.item_id) {
                int item_id = menu_dish.item_id;
                std::string dining_hall = dining_hall_ids.at(menu_dish.dining_hall_id);
                
                // Add date and item to map corresponding to that item id
                favorites_serving_info.at(item_id).insert({date, favorite_dish});
            }
        }
    }
    
    return favorites_serving_info;
}

std::string FavoritesProcessor::GetChart() {
    
}
