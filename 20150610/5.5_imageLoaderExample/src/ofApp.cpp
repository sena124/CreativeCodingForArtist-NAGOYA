#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	testIcon.loadImage("images/test_img.jpg");
	testIcon.setImageType(OF_IMAGE_GRAYSCALE);
}

//--------------------------------------------------------------
void ofApp::update(){
	ofBackground(255);	
}

//--------------------------------------------------------------
void ofApp::draw(){	

	int w = testIcon.getWidth();
	int h = testIcon.getHeight();
	float diameter = 10;

	unsigned char* pixels = testIcon.getPixels();
	ofSetColor(0, 0, 255);
	for(int y = 0; y < h; y++) {
		for(int x = 0; x < w; x++) {
			int index = y * w + x;
			unsigned char cur = pixels[index];
			float size = 1 - ((float) cur / 255);
			ofCircle(x * diameter, y * diameter, 1 + size * diameter / 2);
		}
	}
	
	ofSetColor(255);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
