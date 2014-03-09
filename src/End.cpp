//
//  End.cpp
//  cloudSending
//
//  Created by NAOYAIWAMOTO on 2014/03/05.
//
//

#include "End.h"

//--------------------------------------------------------------
string End::getName()
{
	return "End";
}


//--------------------------------------------------------------
void End::setup()
{
    // initialize
    init();
    
    // image
    thankyou.loadImage("End/img/thankyou.png");
    end.loadImage("End/img/finish.png");
}


//--------------------------------------------------------------
void End::init()
{
    _count = 0;
    getSharedData().counter = 0;
}



void End::update()
{
    // timer for each 1 second
	if (ofGetElapsedTimeMillis() - getSharedData().lastUpdate > 1000)
	{
		getSharedData().counter++;
		getSharedData().lastUpdate = ofGetElapsedTimeMillis();
        
        if (getSharedData().counter > 5) {
            init();
            changeCamera(getSharedData().qrcodeCamId);
            changeState("Start");
        }
    }
}

void End::draw()
{
    ofSetColor(255);
    
    thankyou.resize(ofGetWidth(), ofGetHeight());
    end.resize(ofGetWidth(), ofGetHeight());
   
    if(_count % 2 == 0)
        thankyou.draw(0, 0);
    else
        end.draw(0, 0);
}

void End::mousePressed(int x, int y, int button)
{
    init();
    changeCamera(getSharedData().qrcodeCamId);
	changeState("Start");
}


//--------------------------------------------------------------
void End::keyPressed(int key){
    switch (key) {
        case 'a':
            init();
            changeState("Print");
            break;
            
        case 's':
            init();
            changeCamera(getSharedData().qrcodeCamId);
            changeState("Start");
            break;
            
        case ' ':
            _count++;
            if(_count > 2){
                _count = 0;
            }
            break;
            
        default:
            break;
    }
}


//--------------------------------------------------------------
void End::changeCamera(int id){
    getSharedData().cam.close();
    getSharedData().cam.setDeviceID(id);
    getSharedData().cam.initGrabber(640,480); // change this to your settings
}
