#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    UserProcessor processor;
    processor.GetUserInput();
    std::vector<std::string> dishes = processor.GetFavoriteDishesVector();
    output_message = "Your favorite dishes:\n";

    for (std::string dish : dishes) {
        output_message += dish + "\n";
        output_message.append("\n");
    }
    
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
