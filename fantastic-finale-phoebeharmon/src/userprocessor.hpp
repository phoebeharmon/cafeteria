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
#include <fstream>
#include <sstream>

#endif /* userprocessor_hpp */

class UserProcessor {
public:
    /**
     Call helper methods in order to display items as well as get and deal with user input
     */
    void HandleUserInput();
    
    /**
     Return vector of all unique dishes
     */
    std::vector<Item> GetDishes();
    
    /**
     Check that the given dish is not already in the given vector
     */
    bool CheckValidDish(std::string dish, std::vector<Item> dishes);
    
    /**
     Returns Item object corresponding to a name of a dish from a vector of Items
     */
    Item GetItem(std::string dish, std::vector<Item> dishes);
    
    /**
     Generate vector of favorite dishes based on user input
     */
    void RequestFavoriteDishes(std::vector<Item> dishes);
    
    /**
     Return vector of favorite dishes
     */
    std::vector<Item> GetFavoriteDishes();
    
    /**
     Save information about all items into a file
     */
    void SaveItemsToFile();
    
    /**
     Save information about user's favorite items into a file
     */
    void SaveFavoritesToFile();
    
    /**
     Load a file with info about all items into a vector of Item objects
     */
    std::vector<Item> LoadItemsFile();
    
    /**
     Load a file with info about user's favorite items into a vector of Item objects
     */
    void LoadFavoritesFile();

private:
    std::map<int, std::vector<std::string>> meal_id{
        {1, {"Breakfast", "Continental Breakfast"}},
        {2, {"Lunch", "Light Lunch"}},
        {3, {"Dinner", "After Dark Late Dinner"}}};
    std::vector<Item> favorite_dishes;
    std::vector<Item> items_unique;
    int kNumOfDiningHalls = 28;
};
