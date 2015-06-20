#pragma once

#include "ofMain.h"
#include "ofxCv.h"

#include "ofxFaceTracker.h"

class testApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
    //FaceTracker
    ofVideoGrabber cam;
    ofxFaceTracker tracker;
    
    //Arduino
    void setupArduino(const int & version);
    void updateArduino();
    ofImage bgImage;
    ofTrueTypeFont font;
    ofArduino ard;       //Arduinoへの接続
    bool bSetupArduino;  //Arduinoに接続したかのフラグ
    
    int timer;
    string arduino_id;
    bool isDebug;
    
    
};
