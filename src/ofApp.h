#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		// Added for GUI
		ofxPanel guiPanel;
		bool guiHide;
		ofxIntSlider xVel;
		ofxIntSlider yVel;
		ofxColorSlider color;
		ofxButton ringButton;
		//void ringButtonPressed();
		ofSoundPlayer ring;
		ofxLabel msgCoordinates;
		ofxLabel label;
		const string labelText = "Edit text & press enter";
		ofxInputField<std::string> textbox;
		//void exit();

	private:
		string text;
		int xPos;
		int yPos;
		int xSpeed;
		int ySpeed;
		int xDirection;
		int yDirection;
};
