#include "ofApp.h"

const int ofApp::WIDTH;
const int ofApp::HEIGHT;
const int ofApp::NUM_PARTICLES;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofEnableDepthTest();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    cam.setDistance(100);
    
    for (int i =0; i<WIDTH; i++){
        for (int j =0; j <HEIGHT; j++){
            myVerts[j *WIDTH +i].set(i -WIDTH/2 ,j- HEIGHT/2, 0);
            myColor[j *WIDTH +i].set(0.5, 0.8 ,1.0 ,1.0);
        }
    }

    myVbo.setVertexData(myVerts, NUM_PARTICLES, GL_DYNAMIC_DRAW);
    myVbo.setColorData(myColor, NUM_PARTICLES, GL_DYNAMIC_DRAW);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i =0; i<WIDTH; i++){
        for (int j =0; j <HEIGHT; j++){
            
            float x = sin(i *0.1 + ofGetElapsedTimef()) *10.0;
            float y = sin(j *0.15 + ofGetElapsedTimef()) *10.0;
            float z = x +y;
            myVerts[j *WIDTH +i].set(ofVec3f(i -WIDTH /2, j -WIDTH /2, z));
        }
    }
    myVbo.updateVertexData(myVerts, NUM_PARTICLES);
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    glPointSize(2);
    myVbo.draw(GL_POINTS, 0, NUM_PARTICLES);
    cam.end();
    
    string info;
    info = "Vertex num =" + ofToString(NUM_PARTICLES, 0) + "\n";
    ofDrawBitmapString(info, 30, 50);
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