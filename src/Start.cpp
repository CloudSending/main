//
//  Start.cpp
//  cloudSending
//
//  Created by NAOYAIWAMOTO on 2014/03/04.
//
//

#include "Start.h"

//--------------------------------------------------------------
string Start::getName()
{
	return "Start";
}


//--------------------------------------------------------------
void Start::setup()
{
    // img
    topImg.loadImage("Start/top.png");
    
    // movie
    mov.loadMovie("Start/ICC_CS_OP_0309.mov");
    mov.play();


    // set up for reading QR codes (activate camera)
    ofSetVerticalSync(true);
    getSharedData().cam.setDeviceID(getSharedData().qrcodeCamId);
    getSharedData().cam.initGrabber(640, 480);
    initResult = ofxZxing::decode(getSharedData().cam.getPixelsRef(), true);
}


//--------------------------------------------------------------
void Start::init()
{
    result = initResult;
    getSharedData().cam.close();
}


//--------------------------------------------------------------
void Start::update()
{
    mov.update();
    
    getSharedData().counter = -2;
    
	if (ofGetElapsedTimeMillis() - getSharedData().lastUpdate > 1000)
	{
		getSharedData().counter = 0;
		getSharedData().lastUpdate = ofGetElapsedTimeMillis();
	}


    // update for reading QR codes
	getSharedData().cam.update();
	if(getSharedData().cam.isFrameNew()){
		ofxZxing::Result curResult = ofxZxing::decode(getSharedData().cam.getPixelsRef(), true);
		float curTime = ofGetElapsedTimef();
		if(curResult.getFound()){
			result = curResult;
			lastFound = curTime;
		} else if(curTime - lastFound > 1){
            // if we haven't found anything after a second
			result = curResult; // then update anyway
		}
	}

}

void Start::draw()
{
    // img
    topImg.resize(ofGetWidth(), ofGetHeight());
    topImg.draw(0,0);
    
    mov.draw(0, 0);

    // go to the next scene when detected
    if(result.getFound())
    {
        // Scan QR codes and get info
        ticketData = result.getText();

        // go next
        init();
        changeState("Flight");
	}

}


//--------------------------------------------------------------
void Start::mousePressed(int x, int y, int button)
{
//	changeState("Scan");
    init();
    changeState("Flight");
}


//--------------------------------------------------------------
void Start::keyPressed(int key){
    switch (key) {
        case 'a':
            init();
            changeState("End");
            break;
            
        case 's':
            init();
            changeState("Flight");
            break;
            
        case '0':
            changeCameraTest(0);
            break;
            
        case '1':
            changeCameraTest(1);
            break;

        case '2':
            changeCameraTest(2);
            break;

        default :
            break;
    }
}


//--------------------------------------------------------------
void Start::changeCameraTest(int id){
    getSharedData().cam.close();
    getSharedData().cam.setDeviceID(id);
    getSharedData().cam.initGrabber(640,480); // change this to your settings
}



