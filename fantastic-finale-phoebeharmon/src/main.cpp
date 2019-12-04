#include "ofMain.h"
#include "ofApp.h"
#include "dataprocessor.hpp"
#include "userprocessor.hpp"
#include <iostream>
#include <vector>

//========================================================================

int main( ){
	//ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	//ofRunApp(new ofApp());
        
    // Convert url string to vector of Item objects
    
    UserProcessor processor;
    processor.GetUserInput();
    
    /*
    DataProcessor processor;
    std::string hall_id = "1";
    std::string url_string = processor.BuildUrl(hall_id);
    std::string url_content = processor.ReadUrl(url_string);
    nlohmann::json json_object = processor.ConvertStringToJson(url_content);
    std::vector<Item> items = processor.ConvertJsonToItems(json_object);
    
    for (Item element : items) {
        std::cout << element.meal << "\t";
        std::cout << element.course << "\t\t";
        std::cout << element.formal_name << std::endl;
    }*/
}
