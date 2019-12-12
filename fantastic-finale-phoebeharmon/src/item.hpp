//
//  item.hpp
//  fantastic-finale-phoebeharmon
//
//  Created by Phoebe Harmon on 11/19/19.
//

#include <stdio.h>
#include <string>

class Item {
public:
    /**
     Overloads < for Item by comparing the name of the dish
     */
    bool operator< (const Item &other) const;
    
    std::string formal_name;
    std::string course;
    std::string meal;
    std::string ingredients;
    std::string date;
    int item_id;
    int dining_hall_id;
};
