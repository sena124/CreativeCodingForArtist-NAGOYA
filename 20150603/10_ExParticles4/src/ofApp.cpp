#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //背景色を黒に指定
    ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
    //posXとposYに座標を設定
    for (int i =0; i <3; i++){
        particles[i].posX = 400 + (i+1) *100 *sin(ofGetElapsedTimef()/(i+1));
        particles[i].posY = 400 + (i+1) *100 *cos(ofGetElapsedTimef()/(i+1));
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //ofPushStyle()とofPopStyle()で囲むことで各種パラメータの影響範囲を限定
    ofPushStyle();
    for (int i =0; i <sizeof(particles) -1; i++){
        //色を青に指定
        ofSetColor(128, 128, 255);
        //円を描画
        ofCircle(particles[i].posX, particles[i].posY , 20);
    }
    ofPopStyle();
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