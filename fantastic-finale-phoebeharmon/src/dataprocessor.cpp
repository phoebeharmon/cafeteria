//
//  dataprocessor.cpp
//  fantastic-finale-phoebeharmon
//
//  Created by Phoebe Harmon on 11/19/19.
//

#include "dataprocessor.hpp"
#include <curl/curl.h>


std::string DataProcessor::ConvertUrlStringToJsonString(std::string url_string) {
    
}

std::string DataProcessor::ReadUrl(std::string url_string) {
    /*CURL *curl;
    CURLcode response;
    curl = curl_easy_init();
    
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://web.housing.illinois.edu/MobileDining2/WebService/Search.aspx?t=json&k=7A828F94-620B-4EE3-A56F-328036CC3C04&id=4&from=2019-11-20&to=2019-11-20");
     
        response = curl_easy_perform(curl);

        // always cleanup
        curl_easy_cleanup(curl);
        
        
    }*/

}

bool DataProcessor::IsValidUrl(std::string url_string) {
    
}
