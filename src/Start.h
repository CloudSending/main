//
//  Start.h
//  cloudSending
//
//  Created by NAOYAIWAMOTO on 2014/03/04.
//
//

#ifndef __cloudSending__Start__
#define __cloudSending__Start__

#pragma once

#include "ofxState.h"
#include "shareData.h"
#include "ofxTrueTypeFontUC.h"
#include "ofxZxing.h"


class Start : public itg::ofxState<SharedData>
{
public:
    void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);
    void keyPressed(int key);
	string getName();
    void init();

    
    // img
    ofImage topImg;
    
    // e-font
    ofTrueTypeFont font;
    string title1;
    string title2;

    // j-font
    ofxTrueTypeFontUC j_font;
    wstring sampleString;

    // video
    ofVideoPlayer mov;

    //QRcode
    ofxZxing::Result result;
	ofxZxing::Result initResult;
    ofImage logo_ana;
	ofImage logo_jal;
	ofVideoGrabber cam;
	float lastFound;
    string ticketData;
    

};

#endif /* defined(__cloudSending__Start__) */
