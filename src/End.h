//
//  End.h
//  cloudSending
//
//  Created by NAOYAIWAMOTO on 2014/03/05.
//
//

#ifndef __cloudSending__End__
#define __cloudSending__End__


#include "ofxState.h"
#include "shareData.h"
#include "ofxAnimatableFloat.h"

class End : public itg::ofxState<SharedData>
{
public:
    void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);
    void keyPressed(int key);
	string getName();
    
    // image
    ofImage thankyou;
    ofImage end;
    
    // count
    int _count;
};

#endif /* defined(__cloudSending__End__) */
