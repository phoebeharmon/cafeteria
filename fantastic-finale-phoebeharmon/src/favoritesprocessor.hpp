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
#include "userprocessor.hpp"

#endif /* favoritesprocessor_hpp */
class FavoritesProcessor {
public:
    /*
     Get a vector of Item objects for every dining hall for the week after the current week
     */
    std::vector<Item> GetFutureMenu();
    
    /**
    Determine the location and times that the user's favorite dishes will be served
     */
    std::map<int, std::vector<Item>> FindFavoritesInFutureMenu(std::vector<Item> menu, std::vector<Item> favorites);
    
    /**
     Create a chart to neatly display the information about dishes/locations/times
     */
    std::string GetChart(std::map<int, std::vector<Item>>);
private:
    std::map<int, std::string> dining_hall_ids{{1, "Ikenberry"}, {2, "PAR"}, {3, ""}, {4, ""}, {5, "LAR"}, {6, "FAR"}, {7, "57 North"}, {8, ""}, {9, ""}, {10, ""}, {11, ""}, {12, ""}, {13, ""}, {14, ""}, {15, ""}, {16, ""}, {17, ""}, {18, "Chomps"}, {19, ""}, {20, "Better Burger IKE"}, {21, ""}, {22, "FAR Out Pizza"}, {23, ""}, {24, ""}, {25, ""}, {26, ""}, {27, "Blue 41"}, {28, ""}, {29, ""}, {30, ""}, {31, ""}, {32, ""}, {33, ""}, {34, ""}, {35, ""}};
    int kNumOfDiningHalls = 30;
};
