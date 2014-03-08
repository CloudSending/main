//
//  Mission1.cpp
//  cloudSending
//
//  Created by NAOYAIWAMOTO on 2014/03/05.
//
//

#include "Mission1.h"

//--------------------------------------------------------------
string Mission1::getName()
{
	return "Mission1";
}


//--------------------------------------------------------------
void Mission1::setup()
{
    // img
    img.loadImage("Mission1/img/1.png");
    flight.loadImage("Mission1/img/flight.png");
    flight2.loadImage("Mission1/img/flight2.png");
    
    // Animation
    init();
    
    // Arduino
    device.listDevices();
	vector <ofSerialDeviceInfo> deviceList = device.getDeviceList();
	int baud = 19200;
	device.setup(0, baud); //open the first device
}


//--------------------------------------------------------------
void Mission1::init()
{
    x = 0;
    xx = 0;
    p.set(ofGetWidth()/2-90, 1920);
    pp.set(ofGetWidth()/2, 0);
    start = true;
}


//--------------------------------------------------------------
void Mission1::update()
{
    if(start) {
        p.y -= 30;
    }
    
    // each 1 second
	if (ofGetElapsedTimeMillis() - getSharedData().lastUpdate > 1000)
	{
		getSharedData().counter++;
		getSharedData().lastUpdate = ofGetElapsedTimeMillis();
        
        // 時間がたったら次へ
        //if (getSharedData().counter > 21) {
        if (getSharedData().counter > 10) {
            sendSerial(0);    // 0の信号を送る
            
            // initialize
            x = 0;
            xx = 0;
            p.set(ofGetWidth()/2-90, 1920);

            changeState("Mission2");
        }
	}
    
}

void Mission1::draw()
{
    ofSetColor(255);
    img.resize(ofGetWidth(), ofGetHeight());
    img.draw(0, 0);
    
    ofEnableAlphaBlending();
    flight.draw(p.x, p.y);
    ofDisableAlphaBlending();
    
    ofSetColor(255, 102, 102);
    if(p.y > 0){
        ofTriangle(p.x+83, p.y+160, 0, ofGetHeight(), ofGetWidth(), ofGetHeight());
    }else{
        x+=5;
        ofTriangle(p.x+83, p.y+160, -x, ofGetHeight(), ofGetWidth()+x, ofGetHeight());
    }
}


//--------------------------------------------------------------
void Mission1::mousePressed(int x, int y, int button)
{
    // initialize
    init();
	changeState("Mission2");
}


//--------------------------------------------------------------
void Mission1::keyPressed(int key){
    switch (key) {
        case 'a':
            init();
            changeState("Measure3");
            break;
            
        case 's':
            init();
            changeState("Mission2");
            break;

        case ' ':
            start = !start;
            break;
            
        default:
            break;
    }
}


//--------------------------------------------------------------
void Mission1::sendSerial(int data){
    device.writeByte(data);
    sentData = ofToString(data);
}

//--------------------------------------------------------------
void Mission1::readSerial(){
    //TODO
}

