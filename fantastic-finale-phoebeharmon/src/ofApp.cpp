#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    UserProcessor user_processor;
    user_processor.GetUserInput();
    std::vector<Item> favorites = user_processor.GetFavoriteDishes();
    output_message = "Your favorite dishes:\n";

    for (Item dish : favorites) {
        output_message += dish.formal_name + "\n";
        output_message.append("\n");
    }
    
    FavoritesProcessor favorites_processor;
    std::vector<Item> menu = favorites_processor.GetFutureMenu();
    std::map<int, std::vector<Item>> serving_info = favorites_processor.FindFavoritesInFutureMenu(menu, favorites);
    std::string chart = favorites_processor.GetChart(serving_info);
    
    output_message.append("\n--------------Where to get your favorite dishes next week:-------------------\n");
    output_message.append(chart);
    
    ofBackground(254, 236, 255);
    //font.loadFont("verdana.ttf", 80);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    //ofClear(0);
    ofSetColor(0);
    ofDrawBitmapString(output_message, 150, 150);
    //font.drawString(output_message, 150, 150);
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
