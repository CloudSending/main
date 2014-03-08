//
//  Mission2.h
//  cloudSending
//
//  Created by NAOYAIWAMOTO on 2014/03/05.
//
//

#ifndef __cloudSending__Mission2__
#define __cloudSending__Mission2__

#include "ofxState.h"
#include "shareData.h"

class Mission2 : public itg::ofxState<SharedData>
{
public:
    void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);
    void keyPressed(int key);
    
	string getName();
  
    // img
    ofImage *img;

    // 仮変数
    int _count;
    
};

#endif /* defined(__cloudSending__Mission2__) */
