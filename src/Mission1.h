//
//  Mission1.h
//  cloudSending
//
//  Created by NAOYAIWAMOTO on 2014/03/05.
//
//

#ifndef __cloudSending__Mission1__
#define __cloudSending__Mission1__


#include "ofxState.h"
#include "shareData.h"

class Mission1 : public itg::ofxState<SharedData>
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
    ofImage img;
    ofImage flight;
    ofImage flight2;
    
    ofPoint p, pp;
    float x, xx;
    
    bool start;
    
    // Arduino
    void sendSerial(int data);
    void readSerial();
    string sentData;
    ofSerial	device;

    
};

#endif /* defined(__cloudSending__Mission1__) */
