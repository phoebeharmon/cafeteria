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
    /**
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
    std::map<int, std::string> dining_hall_ids{{1, "Ikenberry"}, {2, "PAR\t"}, {3, "ISR\t"}, {4, "Busey-Evans"}, {5, "LAR\t"}, {6, "FAR\t\t"}, {7, "57 North\t"}, {8, "Cracked Egg"}, {9, "Caffeinator"}, {10, "La Cocina"}, {11, "Busey Bean & Green"}, {12, "Field of Greens"}, {13, "Leafy!\t"}, {14, "Urbana South Market"}, {15, "Cafeteria"}, {16, "Soul Ingredient"}, {17, "Taste of Asia"}, {18, "Chomps\t"}, {19, "Oodles\t"}, {20, "Better Burger IKE"}, {21, "Neo Soul\t"}, {22, "FAR Out Pizza"}, {23, "Kosher Kitchen"}, {24, "d i s h\t"}, {25, "Better Burger"}, {26, "ARC Ignite"}, {27, "Blue 41\t"}, {28, "Orange on Green"}};
    int kNumOfDiningHalls = 28;
};
