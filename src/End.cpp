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

string End::getName()
{
	return "End";
}

void End::keyPressed(int key){
    switch (key) {
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