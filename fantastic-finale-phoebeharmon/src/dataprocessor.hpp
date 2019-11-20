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

#endif /* dataprocessor_hpp */

class DataProcessor {
public:
    std::string ConvertUrlStringToJsonString(std::string url_string);
    std::string ReadUrl(std::string url_string);
    bool IsValidUrl(std::string url_string);
};
