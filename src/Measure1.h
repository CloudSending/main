//
//  Measure1.h
//  cloudSending
//
//  Created by NAOYAIWAMOTO on 2014/03/04.
//
//

#ifndef __cloudSending__Measure1__
#define __cloudSending__Measure1__

#include "ofxState.h"
#include "shareData.h"
#include "ofxTrueTypeFontUC.h"
#include "ofxAnimatableFloat.h"

class Measure1 : public itg::ofxState<SharedData>
{
public:
    void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);
    
    // img
    ofImage topImg;
    
    // font
    ofxTrueTypeFontUC myFont;
    wstring sampleString;
    wstring sampleString2;
    ofPoint p1, p2, p3;
    
    // animation
    ofImage img;
    ofxAnimatableFloat f;
    ofxAnimatableFloat pos;
    string curveNames;

    // connection
	string getName();
    
};
#endif /* defined(__cloudSending__Measure1__) */
