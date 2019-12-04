//
//  userprocessor.hpp
//  fantastic-finale-phoebeharmon
//
//  Created by Phoebe Harmon on 12/3/19.
//

#ifndef userprocessor_hpp
#define userprocessor_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <map>

#endif /* userprocessor_hpp */

class UserProcessor {
public:
    void GetUserInput();
    std::string DisplayDishes(int meal);
    bool CheckValidMeal(int meal);
private:
    std::map<int, std::vector<std::string>> meal_id{
        {1, {"Breakfast", "Continental Breakfast"}},
        {2, {"Lunch", "Light Lunch"}},
        {3, {"Dinner", "After Dark Late Dinner"}}};
};
