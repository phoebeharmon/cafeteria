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

std::vector<std::string> DateCalculator::GetDates() {
    std::vector<std::string> date_one_vector = GetCurrentDate();
    std::string date_one = ConvertDateVectorToString(date_one_vector);
    std::string date_two = GetWeekLaterDate(date_one_vector);
    std::vector<std::string> dates = {date_one, date_two};
    
    return dates;
}

std::vector<std::string> DateCalculator::GetCurrentDate() {
    // Get current date
    std::time_t current_time = std::time(0);
    std::string current_date = std::ctime(&current_time);
    
    // Magic numbers???
    std::string month = months.at(current_date.substr(4, 3));
    std::string day = current_date.substr(8, 2);
    std::string year = current_date.substr(20, 4);
    std::vector<std::string> date = {year, month, day};
    //std::cout << "\ndate: " << year << " " << month << " " << day;
    
    return date;
}

std::string DateCalculator::GetWeekLaterDate(std::vector<std::string> initial_date) {
    int initial_year = ConvertDateStringToInt(initial_date[0]);
    int initial_month = ConvertDateStringToInt(initial_date[1]);
    int initial_day = ConvertDateStringToInt(initial_date[2]);
    
    
    // Update day
    // If initial_day + 6 > num of days in month, add one to month and update day
    /*if (initial_day + 6 > month_num_of_days.at(initial_month)) {
        
    }
    
    // Update month
    
    // Update year
    
    if (months.at(month)[0] == '0') {
        day = '0' + day;
    }
    std::string later_date = year + "-" + months.at(month) + "-" + day;
    //std::cout << "date: " << url_date_one;*/
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
