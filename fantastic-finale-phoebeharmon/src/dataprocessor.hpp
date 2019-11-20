//
//  dataprocessor.hpp
//  fantastic-finale-phoebeharmon
//
//  Created by Phoebe Harmon on 11/19/19.
//

#ifndef dataprocessor_hpp
#define dataprocessor_hpp

#include <stdio.h>
#include <string>
#include <curl/curl.h>
#include <json.hpp>


#endif /* dataprocessor_hpp */

class DataProcessor {
public:
    //std::string ConvertUrlStringToJsonString(std::string url_string);
    std::string ReadUrl(std::string url_string);
    nlohmann::json ConvertStringToJson(std::string json_string);

    //bool IsValidUrl(std::string url_string);
};

size_t WriteFunction(void *ptr, size_t size, size_t nmemb, std::string* data);
