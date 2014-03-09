//
//  Flight.h
//  cloudSending
//
//  Created by NAOYAIWAMOTO on 2014/03/04.
//
//

#ifndef __cloudSending__Flight__
#define __cloudSending__Flight__

#pragma once

#include "ofxState.h"
#include "shareData.h"
#include "ofxTrueTypeFontUC.h"

class Flight : public itg::ofxState<SharedData>
{
public:
    void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);
    void keyPressed(int key);
	string getName();
    void init();
    void changeCamera(int id);

    
    
    ofImage mapImg;
    ofImage flightImg;
    
    bool change;
};

#endif /* defined(__cloudSending__Flight__) */
