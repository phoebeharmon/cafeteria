//
//  dataprocessor.cpp
//  fantastic-finale-phoebeharmon
//
//  Created by Phoebe Harmon on 11/19/19.
//

#include "dataprocessor.hpp"
#include <cstring>
#include <iostream>

std::string DataProcessor::BuildUrlDay(std::string hall_id, std::string date) {
    std::string url_string = kUrlBase + hall_id + "&from=" + date + "&to=" + date;
    item_date = date;
    
    return url_string;
}

std::string DataProcessor::ReadUrl(std::string url_string) {
    // Start a libcurl easy session
    // Returns a CURL easy handle
    auto curl = curl_easy_init();
    
    // Convert std::string to char array
    int length = url_string.length();
    char char_array[length + 1];
    strcpy(char_array, url_string.c_str());
    
    // The following code is derived from:
    // https://gist.github.com/whoshuu/2dc858b8730079602044
    if (curl) {
        std::string response_string;

        // Set options for a curl easy handle
        curl_easy_setopt(curl, CURLOPT_URL, char_array);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteFunction);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
    
        // Perform a blocking file transfer
        curl_easy_perform(curl);
        
        // End a libcurl easy handle
        curl_easy_cleanup(curl);
        curl = NULL;

        return response_string;
    }
    
    return NULL;
}

nlohmann::json DataProcessor::ConvertStringToJson(std::string json_string) {
    auto json_object = nlohmann::json::parse(json_string);
    
    return json_object;
}

std::vector<Item> DataProcessor::ConvertJsonToItems(nlohmann::json json_object) {
    nlohmann::json menu = json_object.at("Menus");
    nlohmann::json items_json = menu.at("Item");
    std::vector<Item> items;
    
    for (nlohmann::json item_json : items_json) {
        Item item;
        item.formal_name = item_json.at("FormalName");
        item.item_id = item_json.at("ItemID");
        item.course = item_json.at("Course");
        item.dining_hall_id = item_json.at("DiningOptionID");
        item.ingredients = item_json.at("Traits");
        item.meal = item_json.at("Meal");
        item.date = item_date;

        items.push_back(item);
    }
    
    return items;
}

size_t WriteFunction(void *ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*) ptr, size * nmemb);
    
    return size * nmemb;
}
