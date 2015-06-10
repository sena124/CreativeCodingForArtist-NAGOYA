#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    counter = 0;
    ofBackground(255,255,255);
    bSmooth = false;
    ofSetWindowTitle("graphics example");
    
    ofSetFrameRate(60); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.
}

//--------------------------------------------------------------
void ofApp::update(){
    counter = counter + 0.033f;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofFill();
    for (int i = 0; i < 200; i++){
        ofSetColor((int)ofRandom(0,255),(int)ofRandom(0,128),(int)ofRandom(0,128));
        ofRect(ofRandom(0, ofGetWidth()),ofRandom(posY-40, posY+40),ofRandom(10,40),ofRandom(10,40));
        
        ofRect(ofRandom(posX-40, posX+40),ofRandom(0, ofGetHeight()),ofRandom(10,40),ofRandom(10,40));
    }
    
}


//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased  (int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    posX =x;
    posY =y;
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    posX =x;
    posY =y;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    posX =x;
    posY =y;
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
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