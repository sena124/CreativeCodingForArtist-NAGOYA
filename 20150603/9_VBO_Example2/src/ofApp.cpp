#include "ofApp.h"

const int ofApp::WIDTH;
const int ofApp::HEIGHT;
const int ofApp::NUM_PARTICLES;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofEnableDepthTest();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    cam.setDistance(400);
    myVideo.initGrabber(640, 480);
    
    
    for (int i =0; i<WIDTH; i++){
        for (int j =0; j <HEIGHT; j++){
            myVerts[j *WIDTH +i].set(i -WIDTH/2 ,j- HEIGHT/2, 0);
            myColor[j *WIDTH +i].set(1.0, 1.0 ,1.0 ,1.0);
        }
    }

    myVbo.setVertexData(myVerts, NUM_PARTICLES, GL_DYNAMIC_DRAW);
    myVbo.setColorData(myColor, NUM_PARTICLES, GL_DYNAMIC_DRAW);
}

//--------------------------------------------------------------
void ofApp::update(){
    myVideo.update();
    if(myVideo.isFrameNew()){
        unsigned char *pixels = myVideo.getPixels();
        for (int i =0; i<WIDTH; i++){
            for (int j =0; j <HEIGHT; j++){
                
                float r =(float)pixels[j *myVideo.width *3 +i *3] /256.0;
                float g =(float)pixels[j *myVideo.width *3 +i *3 +1] /256.0;
                float b =(float)pixels[j *myVideo.width *3 +i *3 +2] /256.0;
                
                float brightness = (r +g +b) /3.0f;
                
                myVerts[j *WIDTH +i] =ofVec3f(i -WIDTH/2 ,j -HEIGHT/2, brightness *256.0);
                myColor[j *WIDTH +i] = ofFloatColor(r ,g ,b ,0.8);
            }
        }
    myVbo.updateVertexData(myVerts, NUM_PARTICLES);
    myVbo.updateColorData(myColor, NUM_PARTICLES);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofScale(1 ,-1, 1);
    glPointSize(3);
    myVbo.draw(GL_POINTS, 0, NUM_PARTICLES);
    cam.end();
    
    string info;
    info = "Vertex num =" + ofToString(NUM_PARTICLES, 0) + "\n";
    info += "FPS =" + ofToString(ofGetFrameRate(), 2);
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