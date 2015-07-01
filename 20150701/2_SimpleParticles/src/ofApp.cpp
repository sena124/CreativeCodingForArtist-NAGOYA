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

    loc_x =ofRandom(0, ofGetWidth());
    loc_y =ofRandom(0, ofGetHeight());
    speed_x =ofRandom(-5, 5);
    speed_y =ofRandom(-5, 5);
    radius =ofRandom(4, 40);
    red =ofRandom(0, 255);
    green =ofRandom(0, 255);
    blue =ofRandom(0, 255);
    
    mouse_pressed =false;
}

//--------------------------------------------------------------
void ofApp::update(){

    if (mouse_pressed){
        speed_x =(mouseX -loc_x) /8.0;
        speed_y =(mouseY -loc_y) /8.0;
    }
    
    loc_x =loc_x +speed_x;
    loc_y =loc_y +speed_y;
    
    if (loc_x<0){
        speed_x =speed_x * -1;
    }
    
    if (loc_x>ofGetWidth()){
        speed_x =speed_x * -1;
    }
    
    if (loc_y<0){
        speed_y =speed_y * -1;
    }
    
    if (loc_y>ofGetHeight()){
        speed_y =speed_y * -1;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(red, green, blue, 127);
    ofCircle(loc_x, loc_y, radius);
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
    
    speed_x =ofRandom(-5, 5);
    speed_y =ofRandom(-5, 5);
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