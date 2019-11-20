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


#endif /* dataprocessor_hpp */

size_t WriteFunction(void *ptr, size_t size, size_t nmemb, std::string* data);


class DataProcessor {
public:
    //std::string ConvertUrlStringToJsonString(std::string url_string);
    std::string ReadUrl(std::string url_string);
    //bool IsValidUrl(std::string url_string);
};
