//
//  item.cpp
//  fantastic-finale-phoebeharmon
//
//  Created by Phoebe Harmon on 11/19/19.
//

#include "item.hpp"

bool Item::operator< (const Item &other) const {
    return formal_name < other.formal_name;
}
