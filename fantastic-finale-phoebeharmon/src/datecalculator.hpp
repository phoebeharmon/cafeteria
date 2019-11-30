//
//  datecalculator.hpp
//  fantastic-finale-phoebeharmon
//
//  Created by Phoebe Harmon on 11/30/19.
//

#ifndef datecalculator_hpp
#define datecalculator_hpp

#include <stdio.h>
#include <string>

#endif /* datecalculator_hpp */

class DateCalculator {
public:
    std::string GetDateString();
    std::string GetWeekLaterDate(std::string date);
    int ConvertDateStringToInt(std::string date);
};
