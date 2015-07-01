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
    for (int i =0; i <100; i++){
        particle[i].loc_x =ofRandom(0, ofGetWidth());
        particle[i].loc_y =ofRandom(0, ofGetHeight());
        particle[i].speed_x =ofRandom(-5, 5);
        particle[i].speed_y =ofRandom(-5, 5);
        particle[i].radius =ofRandom(4, 40);
        particle[i].red =ofRandom(0, 255);
        particle[i].green =ofRandom(0, 255);
        particle[i].blue =ofRandom(0, 255);
    }
    
    mouse_pressed =false;
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i =0; i<100; i++){
        
        if (mouse_pressed){
            particle[i].setSpeed(mouseX, mouseY, true);
        }
        particle[i].setSpeed(mouseX, mouseY, false);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i =0; i <100; i++){
        ofSetColor(particle[i].red, particle[i].green, particle[i].blue, 127);
        ofCircle(particle[i].loc_x, particle[i].loc_y, particle[i].radius);
    }
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
    
    for (int i =0; i <100; i++){
        particle[i].speed_x =ofRandom(-5, 5);
        particle[i].speed_y =ofRandom(-5, 5);
    }

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