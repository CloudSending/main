//
//  Print.h
//  cloudSending
//
//  Created by NAOYAIWAMOTO on 2014/03/05.
//
//

#ifndef __cloudSending__Print__
#define __cloudSending__Print__

#include "ofxState.h"
#include "shareData.h"
#include "ofxAnimatableFloat.h"

class Print : public itg::ofxState<SharedData>
{
public:
    void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);
    void keyPressed(int key);
	string getName();
    
    ofImage bg1, bg2;
    ofImage reciept;
    
    // animation
    ofxAnimatableFloat pos;
    string curveNames;
    AnimCurve curve;
    
    // Flight Animation
    // img
    ofImage *img;
    ofImage flight;
    
    // 仮変数
    int _count;
    ofPoint p, pp;
    float width_x, xx;
    int vel;
    

};

#endif /* defined(__cloudSending__Print__) */
