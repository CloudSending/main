//
//  Scan.h
//  cloudSending
//
//  Created by NAOYAIWAMOTO on 2014/03/07.
//
//

#ifndef __cloudSending__Scan__
#define __cloudSending__Scan__


#pragma once

#include "ofxState.h"
#include "shareData.h"
#include "ofxTrueTypeFontUC.h"

class Scan : public itg::ofxState<SharedData>
{
public:
    void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);
    void keyPressed(int key);
	string getName();
    
    // img
    ofImage topImg;
    ofImage SecondImg;

    // change
    bool scanned;

    // animation
    vector<float> vec;
    float theta;
};

#endif /* defined(__cloudSending__Scan__) */
