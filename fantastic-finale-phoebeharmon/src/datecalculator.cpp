//
//  datecalculator.cpp
//  fantastic-finale-phoebeharmon
//
//  Created by Phoebe Harmon on 11/30/19.
//

#include "datecalculator.hpp"
#include <ctime>
#include <map>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> DateCalculator::GetWeekDatesVector() {
    std::vector<std::string> dates;
    std::vector<std::string> date_now = GetCurrentDate();
    for (int day = 0; day < 7; day++) {
        dates.push_back(ConvertDateVectorToString(date_now));
        std::vector<std::string> next_date = GetDayLaterDate(date_now);
        date_now = next_date;
    }
    
    return dates;
}

std::vector<std::string> DateCalculator::GetWeekLaterDatesVector() {
    std::vector<std::string> dates;
    std::vector<std::string> date_now = GetWeekLaterDate(GetCurrentDate());
    
   for (int day = 0; day < 7; day++) {
        dates.push_back(ConvertDateVectorToString(date_now));
        std::vector<std::string> next_date = GetDayLaterDate(date_now);
        date_now = next_date;
    }
    
    return dates;
}

std::vector<std::string> DateCalculator::GetCurrentDate() {
    // Get current date
    std::time_t current_time = std::time(0);
    std::string current_date = std::ctime(&current_time);
    
    std::string month = months.at(current_date.substr(4, 3));
    std::string day = current_date.substr(8, 2);
    std::string year = current_date.substr(20, 4);
    
    // Deal with single digit days
    if (day.substr(0,1) == " ") {
        day = day.substr(1,1);
    }
    
    std::vector<std::string> date = {year, month, day};
    
    return date;
}

std::vector<std::string> DateCalculator::GetWeekLaterDate(std::vector<std::string> initial_date) {
    int initial_year = ConvertDateStringToInt(initial_date[0]);
    int initial_month = ConvertDateStringToInt(initial_date[1]);
    int initial_day = ConvertDateStringToInt(initial_date[2]);
    
    // Update date
    int later_year = initial_year;
    int later_month = initial_month;
    int later_day = initial_day + 6;
    int days_in_month = month_num_of_days.at(initial_month);

    // Check for new month/year
    if (later_day > days_in_month) {
        later_day -= month_num_of_days.at(initial_month);
        later_month ++;
        if (later_month > kNumOfMonths) {
            later_month = 1;
            later_year ++;
        }
    }
        
    std::vector<std::string> later_date = {std::to_string(later_year), std::to_string(later_month), std::to_string(later_day)};
    
    return later_date;
}

std::vector<std::string> DateCalculator::GetDayLaterDate(std::vector<std::string> initial_date) {
    int initial_year = ConvertDateStringToInt(initial_date[0]);
    int initial_month = ConvertDateStringToInt(initial_date[1]);
    int initial_day = ConvertDateStringToInt(initial_date[2]);
    
    // Update date
    int later_year = initial_year;
    int later_month = initial_month;
    int later_day = initial_day + 1;
    int days_in_month = month_num_of_days.at(initial_month);

    // Check for new month/year
    if (later_day > days_in_month) {
        later_day -= month_num_of_days.at(initial_month);
        later_month ++;
        if (later_month > kNumOfMonths) {
            later_month = 1;
            later_year ++;
        }
    }
        
    std::vector<std::string> later_date = {std::to_string(later_year), std::to_string(later_month), std::to_string(later_day)};
    
    return later_date;
}


int DateCalculator::ConvertDateStringToInt(std::string date_string) {
    std::stringstream value(date_string);
    int date_int = 0;
    value >> date_int;
    
    return date_int;
}

std::string DateCalculator::ConvertDateVectorToString(std::vector<std::string> date) {
    std::string date_string = date[0] + "-" + date[1] + "-" + date[2];
    
    return date_string;
}
