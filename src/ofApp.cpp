#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("GUI Demo PA0");
    xPos = ofRandom(ofGetWidth());
    yPos = ofRandom(ofGetHeight());
    xSpeed = 3;
    ySpeed = 3;
    xDirection = 1;
    yDirection = 1;
    text = "*** GUI PROJECT ***";

    // ADDED FOR GUI
    ringButton.addListener(this, &ofApp::ringButtonPressed);

    guiPanel.setup("Press h hide/show","settings.xml", 20,20);

    guiPanel.add(xVel.setup("xSpeed", 3, 0, 10));
    guiPanel.add(yVel.setup("ySpeed", 4, 0, 10));
    guiPanel.add(color.setup("color", ofColor(100,140, 200), ofColor(0,0,0), ofColor(255,255,255)));

    guiPanel.add(ringButton.setup("ring"));
    guiPanel.add(msgCoordinates.setup("x-y", " "));
    guiPanel.add(label.setup(labelText, guiPanel.getWidth(), 20));
    guiPanel.add(textbox.setup(text, guiPanel.getWidth(), 20));

    guiHide = false;

    ring.load("ring.wav");

}

//--------------------------------------------------------------
void ofApp::update(){
    if(xPos >= ofGetWidth() || xPos <= 0){
        xDirection *= -1;
    }
    if(yPos >= ofGetHeight() || yPos <= 0){
        yDirection *=-1;
    }

    xSpeed = (int)xVel;
    ySpeed = (int)yVel;

    xPos += xSpeed * xDirection;
    yPos += ySpeed * yDirection;

    msgCoordinates = ofToString(xPos) + " - " + ofToString(yPos);
    text = ofToString( textbox.getParameter() );
}

//--------------------------------------------------------------
void ofApp::draw(){
    //ofDrawBitmapString(xPos, ofGetWidth()/2, ofGetHeight()/2);
    //ofDrawBitmapString(yPos, ofGetWidth()/2, ofGetHeight()/2 + 25);
    ofSetColor(color);
    ofDrawBitmapString(text, xPos,yPos);

    if (!guiHide)
    {
        guiPanel.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    switch (key)
    {
    case 'h':
    case 'H':
        guiHide = !guiHide;
        break;
    case ' ':
        color = ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
        break;
    default:
        break;
    }
}

// -------------------------------------------------------------
void ofApp::ringButtonPressed() {
    ring.play();
    text = "ring ring";
}

// -------------------------------------------------------------
void ofApp::exit(){
    ringButton.removeListener(this, &ofApp::ringButtonPressed);
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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