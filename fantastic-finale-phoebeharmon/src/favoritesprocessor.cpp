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
    std::cout << "\nLoading";
    for (int hall_id = 1; hall_id <= kNumOfDiningHalls; hall_id++) {
        std::string hall_id_string = std::to_string(hall_id);
        for (int day = 0; day < 7; day++) {
            std::string url_string = processor.BuildUrlDay(hall_id_string, dates.at(day));
            std::cout << ".";
            std::string url_content = processor.ReadUrl(url_string);
            
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
    //DateCalculator date_calculator;
    //std::string date = date_calculator.ConvertDateVectorToString(date_calculator.GetCurrentDate());
    
    // Initialize map
    std::map<int, std::vector<Item>> favorites_serving_info;
    for (Item dish : favorites) {
        favorites_serving_info.insert({dish.item_id, {}});
    }
    
    for (Item menu_dish : menu) {
        for (Item favorite_dish : favorites) {
            if (menu_dish.item_id == favorite_dish.item_id) {
                //std::string dining_hall = dining_hall_ids.at(menu_dish.dining_hall_id);
                favorites_serving_info.at(menu_dish.item_id).push_back(menu_dish);
            }
        }
    }

    return favorites_serving_info;
}

std::string FavoritesProcessor::GetChart(std::map<int, std::vector<Item>> serving_info) {
    std::string chart;
    
    std::map<int, std::vector<Item>>::iterator it;
    
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
