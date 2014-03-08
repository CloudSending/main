//
//  End.cpp
//  cloudSending
//
//  Created by NAOYAIWAMOTO on 2014/03/05.
//
//

#include "End.h"

void End::setup()
{
    // initialize
    _count = 0;
    
    // image
    thankyou.loadImage("End/img/thankyou.png");
    end.loadImage("End/img/finish.png");
    
    //getSharedData().counter = 0;
}

void End::update()
{
    // timer for each 1 second
	if (ofGetElapsedTimeMillis() - getSharedData().lastUpdate > 1000)
	{
		getSharedData().counter++;
		getSharedData().lastUpdate = ofGetElapsedTimeMillis();
        
        if (getSharedData().counter > 10) {
            getSharedData().counter = 0;
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
    getSharedData().counter = 0;
	changeState("Start");
}


//--------------------------------------------------------------
void End::keyPressed(int key){
    switch (key) {
        case 'a':
            getSharedData().counter = 0;
            changeState("Print");
            break;
            
        case 's':
            getSharedData().counter = 0;
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

string End::getName()
{
	return "End";
}
