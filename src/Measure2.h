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
    void keyPressed(int key);
	string getName();

    
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
};

#endif /* defined(__cloudSending__Measure2__) */
