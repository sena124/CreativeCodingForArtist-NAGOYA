#include "ofApp.h"

//マウスが押されているかの判定
bool mouse_pressed;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    //フレームレートの設定
    ofSetFrameRate(60);
    //円の分割数の設定
    ofSetCircleResolution(64);
    //アルファチャンネル(透明度)を使用可能にする
    ofEnableAlphaBlending();

    //諸々のパラメータの初期値を設定
    particle.loc_x =ofRandom(0, ofGetWidth());
    particle.loc_y =ofRandom(0, ofGetHeight());
    
    mouse_pressed =false;
}

//--------------------------------------------------------------
void ofApp::update(){
        
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(127, 127, 255, 127);
    ofCircle(particle.loc_x, particle.loc_y, 30);

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
    mouse_pressed =true;
    
    mouseX =x;
    mouseY =y;

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    mouse_pressed =false;
    mouseX =x;
    mouseY =y;
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