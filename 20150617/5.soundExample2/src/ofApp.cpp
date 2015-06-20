#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);

    soundFreq =440;
    phase =0;
    ofSoundStreamSetup(2, 0, this, 44100, 1024, 4);
    ofSoundStreamStart();

}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (0<time && time <=50) {
        soundFreq =220;
    }
    if (50<time && time <=100) {
        soundFreq =440;
    }
    if (100<time && time <=150) {
        soundFreq =880;
    }
    if (150<time && time <=200) {
        soundFreq =440;
    }
    if (200<time && time <=250) {
        soundFreq =220;
    }
    if (250<time && time <=300) {
        soundFreq =220;
    }
    if (300<time && time <=350) {
        soundFreq =440;
    }
    if (350<time && time <=400) {
        soundFreq =880;
    }
    if (400<time && time <=450) {
        soundFreq =440;
    }
    if (450<time && time <=500) {
        soundFreq =220;
    }
    
    ofSoundUpdate();
    time++;
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

