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
        loc_x[i] =ofRandom(0, ofGetWidth());
        loc_y[i] =ofRandom(0, ofGetHeight());
        speed_x[i] =ofRandom(-5, 5);
        speed_y[i] =ofRandom(-5, 5);
        radius[i] =ofRandom(4, 40);
        red[i] =ofRandom(0, 255);
        green[i] =ofRandom(0, 255);
        blue[i] =ofRandom(0, 255);
    }
    
    mouse_pressed =false;
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i =0; i<100; i++){
        
        if (mouse_pressed){
            speed_x[i] =(mouseX -loc_x[i]) /8.0;
            speed_y[i] =(mouseY -loc_y[i]) /8.0;
        }
        
        loc_x[i] =loc_x[i] +speed_x[i];
        loc_y[i] =loc_y[i] +speed_y[i];
        
        if (loc_x[i]<0){
            speed_x[i] =speed_x[i] * -1;
        }
        
        if (loc_x[i]>ofGetWidth()){
            speed_x[i] =speed_x[i] * -1;
        }
        
        
        if (loc_y[i]<0){
            speed_y[i] =speed_y[i] * -1;
        }
        
        if (loc_y[i]>ofGetHeight()){
            speed_y[i] =speed_y[i] * -1;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i =0; i <100; i++){
        ofSetColor(red[i], green[i], blue[i], 127);
        ofCircle(loc_x[i], loc_y[i], radius[i]);
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
        speed_x[i] =ofRandom(-5, 5);
        speed_y[i] =ofRandom(-5, 5);
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