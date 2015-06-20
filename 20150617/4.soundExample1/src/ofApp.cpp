#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);

    soundFreq = 440;
    phase = 0;
    ofSoundStreamSetup(2, 0, this, 44100, 1024, 4);
    ofSoundStreamStart();

}

//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();

}

//--------------------------------------------------------------
void ofApp::draw(){
    

}

//--------------------------------------------------------------
void ofApp::audioRequested (float *buf, int bufSize, int nChan) {
    float phasePerSample = TWO_PI * soundFreq / 44100;
    for (int i = 0; i < bufSize; i++) {
        phase += phasePerSample;
        while (phase > TWO_PI) phase -= TWO_PI;
        float value = sin(phase);
        buf[i * nChan    ] = value;
        buf[i * nChan + 1] = value;
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
    
    //ofSoundStreamClose();
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

