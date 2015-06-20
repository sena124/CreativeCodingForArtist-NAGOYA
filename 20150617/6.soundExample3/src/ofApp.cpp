#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);

    soundFreq =440;
    phase =0;
    ofSoundStreamSetup(2, 0, this, 44100, 1024, 4);
    ofSoundStreamStart();
    press =0.5;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofSoundUpdate();
    time++;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0,0,0);
    ofLine(0, 50, ofGetWidth(), 50);
    ofLine(0, 100, ofGetWidth(), 100);
    ofLine(0, 150, ofGetWidth(), 150);
    ofLine(0, 200, ofGetWidth(), 200);
    ofLine(0, 250, ofGetWidth(), 250);
    ofLine(0, 300, ofGetWidth(), 300);
    ofLine(0, 350, ofGetWidth(), 350);
    ofDrawBitmapString(ofToString((int)(pass*10)), 30, 50);
}

//--------------------------------------------------------------
void ofApp::audioRequested (float *buf, int bufSize, int nChan) {
    float phasePerSample = TWO_PI * soundFreq / 44100;
    for (int i = 0; i < bufSize; i++) {
        phase += phasePerSample;
        while (phase > TWO_PI) phase -= TWO_PI;
        float value = sin(phase)*press;
        buf[i * nChan    ] = value;
        buf[i * nChan + 1] = value;
        
        pass =value;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    
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
    
    if (0<y && y <=50) {
        soundFreq =783.99;
    }
    if (50<y && y <=100) {
        soundFreq =698.46;
    }
    if (100<y && y <=150) {
        soundFreq =659.26;
    }
    if (150<y && y <=200) {
        soundFreq =587.33;
    }
    if (200<y && y <=250) {
        soundFreq =523.25;
    }
    if (250<y && y <=300) {
        soundFreq =493.88;
    }
    if (300<y && y <=350) {
        soundFreq =440.00;
    }
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

