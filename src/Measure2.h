//
//  Measure2.h
//  cloudSending
//
//  Created by NAOYAIWAMOTO on 2014/03/05.
//
//

#ifndef __cloudSending__Measure2__
#define __cloudSending__Measure2__

#include "ofxState.h"
#include "shareData.h"
#include "ofxTrueTypeFontUC.h"
#include "ofxAnimatableFloat.h"


class Measure2 : public itg::ofxState<SharedData>
{
public:
    void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);
    
    // img
    ofImage img;
    ofImage longImg;
    
    // animation
    ofxAnimatableFloat f;
    ofxAnimatableFloat pos;
    string curveNames;
    int value;
    
    // font
    ofTrueTypeFont font;
    ofTrueTypeFont font2;
    
	string getName();
    
};

#endif /* defined(__cloudSending__Measure2__) */
