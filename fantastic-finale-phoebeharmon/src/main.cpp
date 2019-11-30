#include "ofMain.h"
#include "ofApp.h"
#include "dataprocessor.hpp"
#include "datecalculator.hpp"
#include <iostream>
#include <vector>

//========================================================================


int main( ){
	//ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	//ofRunApp(new ofApp());
    //https://web.housing.illinois.edu/MobileDining2/WebService/Search.aspx?t=json&k=7A828F94-620B-4EE3-A56F-328036CC3C04&id=1&from=2019-12-02&to=2019-12-02
    std::string url_base = "https://web.housing.illinois.edu/MobileDining2/WebService/Search.aspx?t=json&k=7A828F94-620B-4EE3-A56F-328036CC3C04&id=";
    std::string url_id = "1";
    std::string url_date_one = "2019-12-02";
    std::string url_date_two = "2019-12-02";
    
    std::string url_string = url_base + url_id + "&from=" + url_date_one + "&to=" + url_date_two;
    
    // Get date information
    DateCalculator calculator;
    std::cout << calculator.GetWeekLaterDate(calculator.GetCurrentDate());
    
    
    // Convert url string to vector of Item objects
    DataProcessor processor;
    std::string url_content = processor.ReadUrl(url_string);
    nlohmann::json json_object = processor.ConvertStringToJson(url_content);
    std::vector<Item> items = processor.ConvertJsonToItems(json_object);
    /*
    for (Item element : items) {
        std::cout << element.meal << "\t";
        std::cout << element.course << "\t\t";
        std::cout << element.formal_name << std::endl;
    }*/
}
