//
//  Mission2.cpp
//  cloudSending
//
//  Created by NAOYAIWAMOTO on 2014/03/05.
//
//

#include "Mission2.h"

//--------------------------------------------------------------
string Mission2::getName()
{
	return "Mission2";
}


//--------------------------------------------------------------
void Mission2::setup()
{
    // initialize
    init();

    // image
    img = new ofImage [4];
    for(int i=0; i<4; i++){
        string filename = "Mission2/img/" + ofToString(i) + ".png";
        img[i].loadImage(filename);
        img[i].resize(ofGetWidth(), ofGetHeight());
    }
}


//--------------------------------------------------------------
void Mission2::init()
{
    getSharedData().counter = 0;
    _count = 0;
}


//--------------------------------------------------------------
void Mission2::update()
{
    // each 1 second
	if (ofGetElapsedTimeMillis() - getSharedData().lastUpdate > 1000)
	{
		getSharedData().counter++;
		getSharedData().lastUpdate = ofGetElapsedTimeMillis();
        
        // change images each some seconds, and if it's the last image go next
        if (getSharedData().counter > 5) {
            _count++;
            if(_count == 4){
                init();
                changeState("Print");
            }
            getSharedData().counter = 0;
        }
    }
}

void Mission2::draw()
{
    // image
    ofSetColor(255);    

    img[_count].draw(0.0, 0.0);
}


//--------------------------------------------------------------
void Mission2::mousePressed(int x, int y, int button)
{
    init();
	changeState("Print");
}


//--------------------------------------------------------------
void Mission2::keyPressed(int key){
    switch (key) {
        case 'a':
            init();
            changeState("Mission1");
            break;
            
        case 's':
            _count++;
            if(_count == 4){
                init();
                changeState("Print");
            }
            break;

        case ' ':
            init();
            changeState("Print");
            break;
            
        default:
            break;
    }
}



