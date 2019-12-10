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

std::map<Item, std::vector<std::string>> FavoritesProcessor::FindFavoritesFutureInformation() {
    
}

std::string FavoritesProcessor::GetChart() {
    
}
