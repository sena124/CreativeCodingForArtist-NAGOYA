#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushStyle();
    ofSetColor(0, 0, 255);
    //円の座標をposX, posYで指定
    ofCircle(posX, posY , 50);
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
    //マウスの動きに合わせてposX,posYを変更
    posX =x;
    posY =y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    //マウスの動きに合わせてposX,posYを変更
    posX =x;
    posY =y;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    //マウスの動きに合わせてposX,posYを変更
    posX =x;
    posY =y;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    //マウスの動きに合わせてposX,posYを変更
    posX =x;
    posY =y;
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