//
//  Measure3.h
//  cloudSending
//
//  Created by NAOYAIWAMOTO on 2014/03/08.
//
//

#ifndef __cloudSending__Measure3__
#define __cloudSending__Measure3__

#include "ofxState.h"
#include "shareData.h"
#include "ofxTrueTypeFontUC.h"
#include "ofxAnimatableFloat.h"

class Measure3 : public itg::ofxState<SharedData>
{
public:
    void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);
 	string getName();
   
    ofImage img;
    ofTrueTypeFont font;
    
    // animation
    ofxAnimatableFloat pos;
    AnimCurve curve;
    ofxAnimatableFloat f;
    float limit, limit2;
    vector<float> vec;
    
    int theta;
    int _frame;
};

#endif /* defined(__cloudSending__Measure3__) */
