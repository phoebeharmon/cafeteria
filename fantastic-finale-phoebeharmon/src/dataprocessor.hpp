//
//  dataprocessor.hpp
//  fantastic-finale-phoebeharmon
//
//  Created by Phoebe Harmon on 11/19/19.
//

#include <stdio.h>
#include <curl/curl.h>
#include <json.hpp>
#include "item.hpp"
#include "datecalculator.hpp"

class DataProcessor {
public:
    /**
     Builds URL string for a given date
    */
    std::string BuildUrlDay(std::string hall_id, std::string date);
    
    /**
     Takes a URL in string form and returns the content of that website as a string
     */
    std::string ReadUrl(std::string url_string);
    
    /**
     Takes a json string and converts it to a json object
     */
    nlohmann::json ConvertStringToJson(std::string json_string);
    
    /**
     Takes a json object and converts it to a vector of Item objects
     */
    std::vector<Item> ConvertJsonToItems(nlohmann::json json_object);
private:
    std::string kUrlBase = "https://web.housing.illinois.edu/MobileDining2/WebService/Search.aspx?t=json&k=7A828F94-620B-4EE3-A56F-328036CC3C04&id=";
    std::string item_date;
};

/**
 Helper function for using libcurl library
 */
size_t WriteFunction(void *ptr, size_t size, size_t nmemb, std::string* data);
