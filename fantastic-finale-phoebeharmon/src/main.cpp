#include "ofMain.h"
#include "ofApp.h"
#include "dataprocessor.hpp"
#include <iostream>
#include <vector>

//========================================================================


int main( ){
	//ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	//ofRunApp(new ofApp());
    std::string url_string = "https://web.housing.illinois.edu/MobileDining2/WebService/Search.aspx?t=json&k=7A828F94-620B-4EE3-A56F-328036CC3C04&id=1&from=2019-11-20&to=2019-11-20";
    
    // Convert url string to vector of Item objects
    DataProcessor processor;
    std::string url_content = processor.ReadUrl(url_string);
    nlohmann::json json_object = processor.ConvertStringToJson(url_content);
    std::vector<Item> items = processor.ConvertJsonToItems(json_object);
    
    for (Item element : items) {
        std::cout << element.meal << "\t";
        std::cout << element.course << "\t\t";
        std::cout << element.formal_name << std::endl;
    }
}
