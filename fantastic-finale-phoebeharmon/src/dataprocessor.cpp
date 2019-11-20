//
//  dataprocessor.cpp
//  fantastic-finale-phoebeharmon
//
//  Created by Phoebe Harmon on 11/19/19.
//

#include "dataprocessor.hpp"
#include <cstring>
#include <iostream>

std::string DataProcessor::ReadUrl(std::string url_string) {
    auto curl = curl_easy_init();
    
    // Convert std::string to char array
    int length = url_string.length();
    char char_array[length + 1];
    strcpy(char_array, url_string.c_str());
    
    // The following code is derived from:
    // https://gist.github.com/whoshuu/2dc858b8730079602044
    if (curl) {
        std::string response_string;

        curl_easy_setopt(curl, CURLOPT_URL, char_array);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteFunction);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
    
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        curl = NULL;

        return response_string;
    }
    
    return NULL;
}

nlohmann::json DataProcessor::ConvertStringToJson(std::string json_string) {
    auto json_object = nlohmann::json::parse(json_string);
}

size_t WriteFunction(void *ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*) ptr, size * nmemb);
    
    return size * nmemb;
}
