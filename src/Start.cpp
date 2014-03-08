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
}

void Start::draw()
{
    // img
    topImg.resize(ofGetWidth(), ofGetHeight());
    topImg.draw(0,0);
    
    mov.draw(0, 0);
}

void Start::mousePressed(int x, int y, int button)
{
	changeState("Scan");
}

string Start::getName()
{
	return "Start";
}