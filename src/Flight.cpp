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
	if (ofGetElapsedTimeMillis() - getSharedData().lastUpdate > 1000)
	{
		getSharedData().counter++;
		getSharedData().lastUpdate = ofGetElapsedTimeMillis();
        
        // 時間がたったら次へ
        
        if (getSharedData().counter > 7) {
            change = true;;
        }
        
        if (getSharedData().counter > 10) {
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

void Flight::mousePressed(int x, int y, int button)
{
	changeState("Measure1");
}

string Flight::getName()
{
	return "Flight";
}