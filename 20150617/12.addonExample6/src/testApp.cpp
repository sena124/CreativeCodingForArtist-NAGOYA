#include "testApp.h"

using namespace ofxCv;

void testApp::setup() {
    
    isDebug = false;
    arduino_id = "/dev/tty.usbmodemfd121";
    
    ofSetFrameRate(60);
    
    
    //FaceTracker
    cam.initGrabber(1280, 720);
    tracker.setup();
    
    
    
    //Arduino
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(255,0,130);
    bgImage.loadImage("firmata.png");
    font.loadFont("franklinGothic.otf", 20);
    // デバイスの接続するポートとスピードを設定
    ard.connect(arduino_id, 57600);
    // Arduinoとの接続が確立するのを監視するリスナー
    // 接続が確立したら、setupArduino()を実行
    ofAddListener(ard.EInitialized, this, &testApp::setupArduino);
    // 接続の確立したかどうかのフラグ
    bSetupArduino	= false;
    
    timer = 0;
    
}

void testApp::update() {
    
    //FaceTracker
    cam.update();
    if(cam.isFrameNew()) {
        tracker.update(toCv(cam));
    }
    
    
    //Arduino
    updateArduino();
}

//--------------------------------------------------------------
void testApp::setupArduino(const int & version) {
    // 接続が確立したら、リスナーを削除
    ofRemoveListener(ard.EInitialized, this, &testApp::setupArduino);
    
    // 1〜13の全てのデジタルピンの初期設定(OUTPUTに)
    for (int i = 0; i < 13; i++){
        ard.sendDigitalPinMode(i, ARD_OUTPUT);
    }
    
    // Digital 13 をOUTPUTに
    ard.sendDigitalPinMode(13, ARD_OUTPUT);
    // Analog 0 をAnalog Inに
    ard.sendAnalogPinReporting(0, ARD_ANALOG);
    // Digital 11 をPWMに
    ard.sendDigitalPinMode(11, ARD_PWM);
    // 接続の確立のフラグをtrueに
    bSetupArduino = true;
}

//--------------------------------------------------------------
void testApp::updateArduino(){
    
    // Arduinoをアップデート、全てのデータとメッセージを取得
    ard.update();
    
    // もしArduinoが接続されていたら
    if (bSetupArduino) {
        // Digital 11 のPWMの値を変化させる
        ard.sendPwm(11, (int)(128 + 128 * sin(ofGetElapsedTimef())));
    }
}

//--------------------------------------------------------------
void testApp::draw() {
    
    
    ofBackground(0,0,0);
    
    //FaceTracker
    isDebug? cam.draw(0, 0):
    ofSetLineWidth(2);
    isDebug? tracker.draw():
    ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);
    ofDrawBitmapString(ofToString((int) tracker.getImagePoint(1).x), 10, 40);
    ofDrawBitmapString(ofToString((int) tracker.getImagePoint(1).y), 10, 60);
    ofDrawBitmapString(ofToString((bool) isDebug), 10, 140);
    
    
    //Arduino
    //sendServoAtta®ch(int pin, int minPulse, int maxPulse, int angle)
    //ard.sendServo(int pin, int value, bool force);
    
    
    int diff_x;
    diff_x = 550 - tracker.getImagePoint(1).x;
    ofDrawBitmapString(ofToString((int) diff_x), 10, 80);
    
    int diff_y;
    diff_y = 360 - tracker.getImagePoint(1).y;
    ofDrawBitmapString(ofToString((int) diff_y), 10, 100);
    
    
    if(diff_x <= -550 || diff_x >= 550){
        ard.sendServoAttach(10, 0, 5, 1);
        ard.sendServo(10, 90, true);
    } else if ((diff_x > -550 || diff_x < 550)){
        ard.sendServoAttach(10, 0, 5, 1);
        ard.sendServo(10, 90 + diff_x/6, true);
    }
    
    
    if(diff_y <= -360 || diff_y >= 360){
        ard.sendServoAttach(9, 0, 5, 1);
        ard.sendServo(9, 90, true);
    } else if(diff_y > -360 || diff_y < 360){
        ard.sendServoAttach(9, 0, 5, 1);
        ard.sendServo(9, 90 + diff_y/6, true);
    }
    
    //何かあった時のために再起動
    timer++;
    ofDrawBitmapString(ofToString((int) timer), 10, 120);
    if(timer>100){
        //Arduino
        ofSetVerticalSync(true);
        ofSetFrameRate(60);
        ofBackground(0,0,0);
        bgImage.loadImage("firmata.png");
        font.loadFont("franklinGothic.otf", 20);
        // デバイスの接続するポートとスピードを設定
        ard.connect(arduino_id, 57600);
        // Arduinoとの接続が確立するのを監視するリスナー
        // 接続が確立したら、setupArduino()を実行
        ofAddListener(ard.EInitialized, this, &testApp::setupArduino);
        // 接続の確立したかどうかのフラグ
        bSetupArduino	= false;
        
        timer = 0;
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key) {
    
    //    //FaceTracker
    //    if(key == 'r') {
    //        tracker.reset();
    //    }
    
    
    if(key == 'd') {
        isDebug = true;
    }
    
    if(key == 'r') {
        isDebug = false;
    }
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    //Arduino
    // マウスプレスでDigital 13をON
    ard.sendDigital(13, ARD_HIGH);
    
    
    //ard.sendServoAttach(9, 0, 5, 1);
    //ard.sendServo(9, 180, true);
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
    //Arduino
    // マウスリリースでDigital 13をOFF
    ard.sendDigital(13, ARD_LOW);
    
    
    //ard.sendServoAttach(9, 0, 5, 1);
    //ard.sendServo(9, 0, true);
    
}




