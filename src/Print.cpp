//
//  Print.cpp
//  cloudSending
//
//  Created by NAOYAIWAMOTO on 2014/03/05.
//
//

#include "Print.h"

void Print::setup()
{
    // image
    bg1.loadImage("Print/img/top.jpg");
    bg2.loadImage("Print/img/under.jpg");
    reciept.loadImage("Print/img/reciept.png");
    
    // Animation
    ofxAnimatableFloat f;
	f.animateFromTo( 0, 150 ); //suitcase
	f.setDuration(1.8);
	//f.setRepeatType( LOOP_BACK_AND_FORTH );
	f.setRepeatType( LOOP ); //PLAY_ONCE
    pos = f;
    curve = (AnimCurve) (EASE_IN_EASE_OUT);
    pos.setCurve( curve );
    curveNames = ofxAnimatable::getCurveName( curve );
    
    // initialize
    vel = 20;
    _count = 2;
    p.set(250, 900);
    pp.set(ofGetWidth()/2,-100);
    width_x = 0;
    xx = 0;
    
    flight.loadImage("Mission2/img/flight2.png");
    flight.resize(120, 120);
    
    
}

void Print::update()
{
    float dt = 1.0f / ofGetFrameRate();
    pos.update( dt );
}

void Print::draw()
{
    ofSetColor(255);
    //bg1.resize(ofGetWidth(), 330);
    //bg2.resize(ofGetWidth(), 470);
    //reciept.resize(180, 200+pos.val());

    ofEnableAlphaBlending();
    bg2.draw(0, 800);
    reciept.draw(350, 350+2*pos.val());
    bg1.draw(0,0);
    ofDisableAlphaBlending();
    
 
    // Flight Animation
    ofSetColor(255, 102, 102);
    if(pp.y < ofGetHeight())
    {
        pp.y += vel;
        ofBeginShape();
        ofVertex(0, ofGetHeight());
        ofVertex(0,0);
        ofVertex(pp.x, pp.y);
        ofVertex(ofGetWidth(),0);
        ofVertex(ofGetWidth(), ofGetHeight());
        ofEndShape();
        
        // 飛行機
        ofSetColor(255);
        ofEnableAlphaBlending();
        flight.draw(ofGetWidth()/2-60, pp.y);
        ofDisableAlphaBlending();
    }else{
        width_x+=7;
        pp.y += vel;
        ofBeginShape();
        ofVertex(0, ofGetHeight());
        ofVertex(-width_x,0);
        ofVertex(pp.x, pp.y);
        ofVertex(ofGetWidth()+width_x,0);
        ofVertex(ofGetWidth(), ofGetHeight());
        ofEndShape();
    }
}

void Print::mousePressed(int x, int y, int button)
{
    p.set(250, 900);
    pp.set(ofGetWidth()/2,-100);
    width_x = 0;
    xx = 0;
	changeState("End");
}

string Print::getName()
{
	return "Print";    
}
