#include "testApp.h"

using namespace ofxCv;

void testApp::setup() {
    ofSetFrameRate(60);
    
    //FaceTracker
    cam.initGrabber(1280, 720);
    tracker.setup();
}

//--------------------------------------------------------------
void testApp::update() {
    //FaceTracker
    cam.update();
    if(cam.isFrameNew()) {
        tracker.update(toCv(cam));
    }
}

//--------------------------------------------------------------
void testApp::draw() {
    
    
    ofBackground(0,0,0);
    
    //FaceTracker
    isDebug? cam.draw(0, 0):
    ofSetLineWidth(2);
    isDebug? tracker.draw():
    ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);
    ofDrawBitmapString(ofToString((int) tracker.getImagePoint(1).x), 10, 40);
    ofDrawBitmapString(ofToString((int) tracker.getImagePoint(1).y), 10, 60);
    ofDrawBitmapString(ofToString((bool) isDebug), 10, 140);
    
    int diff_x;
    diff_x = 640 - tracker.getImagePoint(1).x;
    ofDrawBitmapString(ofToString((int) diff_x), 10, 80);
    
    int diff_y;
    diff_y = 360 - tracker.getImagePoint(1).y;
    ofDrawBitmapString(ofToString((int) diff_y), 10, 100);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key) {
    if(key == 'd') {
        isDebug = true;
    }
    
    if(key == 'r') {
        isDebug = false;
    }
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}




