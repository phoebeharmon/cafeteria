#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxInputField.h"
#include "ofxLabel.h"
#include "favoritesprocessor.hpp"
#include "ofxButton.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void buttonPressed();
        ofxPanel gui;
        ofxTextField textField, text, text2, text3;
        ofxLabel label_meal;
        ofxButton button_breakfast, button_lunch, button_dinner;

    private:
        std::string output_message;
        ofTrueTypeFont font;
		
};
