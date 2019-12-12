//
//  item.hpp
//  fantastic-finale-phoebeharmon
//
//  Created by Phoebe Harmon on 11/19/19.
//

#ifndef item_hpp
#define item_hpp

#include <stdio.h>
#include <string>

#endif /* item_hpp */

class Item {
public:
    bool operator< (const Item &other) const;
    std::string formal_name;
    std::string course;
    std::string meal;
    std::string ingredients;
    std::string date;
    int item_id;
    int dining_hall_id;
};
