//
//  Flight.cpp
//  cloudSending
//
//  Created by NAOYAIWAMOTO on 2014/03/04.
//
//

#include "Flight.h"

void Flight::setup()
{
    mapImg.loadImage("Flight/img-04.png");
    mapImg.resize(ofGetWidth(), ofGetHeight());
    flightImg.loadImage("Flight/img-05.png");
    flightImg.resize(ofGetWidth(), ofGetHeight());
    
    change = false;
}

void Flight::update()
{
    // each 1 second
	if (ofGetElapsedTimeMillis() - getSharedData().lastUpdate > 1000){
		getSharedData().counter++;
		getSharedData().lastUpdate = ofGetElapsedTimeMillis();
        
        // flag to change from mapImg to flightImg
        if (getSharedData().counter > 3){
            change = true;
        }

        // go to the next scene
        if (getSharedData().counter > 6){
            change = false;
            getSharedData().counter = 0;
            changeState("Measure1");
        }
	}
}

void Flight::draw()
{
    // 地図
    if(change == false)
    {
        mapImg.draw(0,0);
    }else{
        flightImg.draw(0,0);
    }
}


//--------------------------------------------------------------
void Flight::mousePressed(int x, int y, int button)
{
    change = false;
    getSharedData().counter = 0;
	changeState("Measure1");
}


//--------------------------------------------------------------
void Flight::keyPressed(int key){
    switch (key) {
        case 'a':
            change = false;
            getSharedData().counter = 0;
            changeState("Start");
            break;
            
        case 's':
            change = false;
            getSharedData().counter = 0;
            changeState("Measure1");
            break;

        default:
            break;
    }
}


//--------------------------------------------------------------
string Flight::getName()
{
	return "Flight";
}
