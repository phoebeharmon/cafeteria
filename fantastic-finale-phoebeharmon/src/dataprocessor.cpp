//
//  dataprocessor.cpp
//  fantastic-finale-phoebeharmon
//
//  Created by Phoebe Harmon on 11/19/19.
//

#include "dataprocessor.hpp"
#include <string>
class DataProcessor {
public:
    std::string ConvertUrlStringToJsonString(std::string url_string);
    std::string ReadUrl(std::string url_string);
    bool IsValidUrl(std::string url_string);
};
