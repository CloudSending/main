//
//  Start.cpp
//  cloudSending
//
//  Created by NAOYAIWAMOTO on 2014/03/04.
//
//

#include "Start.h"

void Start::setup()
{
    // img
    topImg.loadImage("Start/top.png");
    
    // movie
    mov.loadMovie("Start/0308_FULLHD_2.mov");
    mov.play();


    // set up for reading QR codes (activate camera)
    ofSetVerticalSync(true);
	cam.initGrabber(640, 480);
    initResult = ofxZxing::decode(cam.getPixelsRef(), true);
}

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
	cam.update();
	if(cam.isFrameNew()){
		ofxZxing::Result curResult = ofxZxing::decode(cam.getPixelsRef(), true);
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
        result = initResult;
        // go next
        changeState("Flight");
	}

}


//--------------------------------------------------------------
void Start::mousePressed(int x, int y, int button)
{
//	changeState("Scan");
    result = initResult;
    changeState("Flight");
}


//--------------------------------------------------------------
void Start::keyPressed(int key){
    switch (key) {
        case 'a':
            result = initResult;
            changeState("End");
            break;
            
        case 's':
            result = initResult;
            changeState("Flight");
            break;

        default:
            break;
    }
}


//--------------------------------------------------------------
string Start::getName()
{
	return "Start";
}