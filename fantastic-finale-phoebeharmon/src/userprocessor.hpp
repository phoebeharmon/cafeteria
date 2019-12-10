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
#include "dataprocessor.hpp"
#include <iostream>

#endif /* userprocessor_hpp */

class UserProcessor {
public:
    void GetUserInput();
    std::vector<Item> GetDishes(int meal);
    bool CheckValidMeal(int meal);
    bool CheckValidDish(std::string dish, std::vector<Item> dishes);
    Item GetItem(std::string dish, std::vector<Item> dishes);
    void GetFavoriteDishes(std::vector<Item> dishes);
    std::vector<Item> GetFavoriteDishesVector();
    bool CheckValidDishForMeal(std::string meal_name, std::vector<std::string> meals);
private:
    std::map<int, std::vector<std::string>> meal_id{
        {1, {"Breakfast", "Continental Breakfast"}},
        {2, {"Lunch", "Light Lunch"}},
        {3, {"Dinner", "After Dark Late Dinner"}}};
    std::vector<Item> favorite_dishes;
    std::vector<Item> items;
};
