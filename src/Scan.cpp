//
//  Scan.cpp
//  cloudSending
//
//  Created by NAOYAIWAMOTO on 2014/03/07.
//
//

#include "Scan.h"

//--------------------------------------------------------------
string Scan::getName()
{
	return "Scan";
}


//--------------------------------------------------------------
void Scan::setup()
{
    // img
    topImg.loadImage("Scan/img-02.png");
    topImg.resize(ofGetWidth(), ofGetHeight());
    SecondImg.loadImage("Scan/img-03.png");
    SecondImg.resize(ofGetWidth(), ofGetHeight());
   

    init();
//    scanned = false;
//    theta=0;
}


//--------------------------------------------------------------
void Scan::init()
{
    scanned = false;
    theta=0;
    vec.clear();
}



void Scan::update()
{
	if (ofGetElapsedTimeMillis() - getSharedData().lastUpdate > 1000)
	{
		getSharedData().counter++;
		getSharedData().lastUpdate = ofGetElapsedTimeMillis();
        
        std::cout << getSharedData().counter << "," << scanned << std::endl;
        
        // 時間がたったら次へ
        if (getSharedData().counter > 2) {
            scanned = true;
        }
        
        if (getSharedData().counter > 5) {
            init();
            changeState("Flight");
        }
	}
    
}

void Scan::draw()
{
    if (scanned == false) {
        topImg.draw(0,0);
        
        theta+=2.5;
        vec.push_back(theta);
        
        for( int j=0; j<vec.size(); j++)
        {
            ofPushMatrix();
            ofTranslate(ofGetWidth()/2, ofGetHeight()/2-30);
            ofRotateZ(vec.at(j));
            ofCircle(0, -25*1.41421356, 5);
            ofPopMatrix();
        }
        
    }else{
        SecondImg.draw(0,0);
    }
}


//--------------------------------------------------------------
void Scan::mousePressed(int x, int y, int button)
{
    init();
	changeState("Flight");
}


//--------------------------------------------------------------
void Scan::keyPressed(int key){
    switch (key) {
        case 'a':
            init();
            changeState("Start");
            break;

        case 's':
            init();
            changeState("Flight");
            break;
        default:
            break;
    }
}

