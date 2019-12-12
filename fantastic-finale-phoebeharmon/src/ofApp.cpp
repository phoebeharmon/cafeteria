#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //gui.setup();
    /*gui.add(button_breakfast.setup("Breakfast"));
    gui.add(button_lunch.setup("Lunch"));
    gui.add(button_dinner.setup("Dinner"));
    button_breakfast.addListener(this, &ofApp::buttonPressed);
    //circleResolution.addListener(this, &ofApp::circleResolutionChanged);

    //float height = 100.0;
    //float width = 100.0;
    //gui.add(label_meal.setup("Select meal", height, width));
    //gui.add(textField.setup("textfield:", "your favorite dishes"));*/
    
    
    UserProcessor user_processor;
    user_processor.GetUserInput();
    std::vector<Item> favorites = user_processor.GetFavoriteDishes();
    output_message = "Your favorite dishes:\n";

    for (Item dish : favorites) {
        output_message += dish.formal_name + "\n";
    }
    
    FavoritesProcessor favorites_processor;
    std::vector<Item> menu = favorites_processor.GetFutureMenu();
    std::map<int, std::vector<Item>> serving_info = favorites_processor.FindFavoritesInFutureMenu(menu, favorites);
    std::string chart = favorites_processor.GetChart(serving_info);
    
    output_message.append("\n--------------Where to get your favorite dishes next week:-------------------\n");
    output_message.append(chart);
    
    ofBackground(254, 236, 255);
    //ofBackground(254, 236, 255);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    //gui.draw();
    //ofClear(0);
    ofSetColor(0);
    ofSystemTextBoxDialog("Enter choice: ");
    /*
    ofDrawBitmapString("Select meal: ", 0, 0);
    if (button_breakfast) {
        ofDrawBitmapString("The breakfast dishes: ", 150, 150);
    }*/
    //font.drawString(output_message, 150, 150);
    ofDrawBitmapString(output_message, 150, 150);

}

//--------------------------------------------------------------
void ofApp::buttonPressed(){
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
