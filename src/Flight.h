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
    
    ofImage mapImg;
    ofImage flightImg;
	string getName();
    
    bool change;
};

#endif /* defined(__cloudSending__Flight__) */
