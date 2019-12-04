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
#include <map>

#endif /* datecalculator_hpp */

class DateCalculator {
public:
    std::vector<std::string> GetCurrentDate();
    std::vector<std::string> GetDates();
    std::string GetWeekLaterDate(std::vector<std::string> date);
    int ConvertDateStringToInt(std::string date);
    std::string ConvertDateVectorToString(std::vector<std::string>);
private:
    std::map<std::string, std::string> months{{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};
    std::map<int, int> month_num_of_days{{1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};
    int kNumOfMonths = 12;
};
