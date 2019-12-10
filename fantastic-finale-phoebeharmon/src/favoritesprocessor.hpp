//
//  favoritesprocessor.hpp
//  fantastic-finale-phoebeharmon
//
//  Created by Phoebe Harmon on 12/10/19.
//

#ifndef favoritesprocessor_hpp
#define favoritesprocessor_hpp

#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include "item.hpp"
#include "dataprocessor.hpp"


#endif /* favoritesprocessor_hpp */
class FavoritesProcessor {
public:
    /*
     Get a vector of Item objects for every dining hall for the week after the current week
     */
    std::vector<Item> GetFutureMenu();
    std::map<Item, std::vector<std::string>> FindFavoritesFutureInformation();
    std::string GetChart();
private:
    std::map<int, std::string> dining_hall_ids{{1, "Ikenberry"}, {2, ""}, {3, ""}, {4, ""}, {5, ""}, {6, ""}, {7, ""}, {8, ""}, {9, ""}, {10, ""}, {11, ""}, {12, ""}, {13, ""}, {14, ""}, {15, ""}, {16, ""}, {17, ""}, {18, ""}, {19, ""}, {20, ""}, {21, ""}};
    int kNumOfDiningHalls = 30;
};
