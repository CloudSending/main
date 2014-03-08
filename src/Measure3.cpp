//
//  Measure2.cpp
//  cloudSending
//
//  Created by NAOYAIWAMOTO on 2014/03/05.
//
//

#include "Measure3.h"

void Measure3::setup()
{
    theta = 0;
    
    img.loadImage("Measure3/img/1.jpg");
    img.resize(ofGetWidth(), ofGetHeight());
    
    //font.loadFont("font/avenir-next-medium-sc-latin-1.ttf", 70);
    font.loadFont("font/BebasNeue.otf", 130);

    int x = getSharedData().weight;
    limit = 360*x/32;
    limit2 = x;
    
    // animation
    f.animateFromTo( 0, limit );  // circle
	f.setDuration(4);
	f.setRepeatType( PLAY_ONCE );
    pos = f;
    curve = (AnimCurve) (EASE_IN_EASE_OUT);
    pos.setCurve( curve );
    
    _frame = 0;
}

void Measure3::update()
{
	if (ofGetElapsedTimeMillis() - getSharedData().lastUpdate > 1000)
	{
		getSharedData().counter++;
		getSharedData().lastUpdate = ofGetElapsedTimeMillis();
        
        // 時間がたったら次へ
        if (getSharedData().counter > 18) {
            pos = f;
            vec.clear();
            changeState("Mission1");
        }
	}
    
    float dt = 1.0f / ofGetFrameRate();
    pos.update( dt );
}

void Measure3::draw()
{
    ofSetColor(255);
    img.draw(0, 0);
    
    ofSetColor(255, 51, 153);
    
    // 円描画(ピンク)
    for(int i=0; i<360; i++)
    {
        ofPushMatrix();
        // 450*800
        //ofTranslate(326, 580);
        ofTranslate(750, 1430);
        
        ofRotateZ(i);
        ofVec2f p(130, 130);
        ofCircle(p.x, p.y, 10);
        vec.push_back(pos.val());
        ofPopMatrix();
    }
    
    // アオ
    ofSetColor(0, 102, 204);
    
    // アオの円描画
    for( int j=0; j<vec.size(); j++)
    {
        ofPushMatrix();
        //ofTranslate(326, 580);
        ofTranslate(750, 1430);
        ofRotateZ(vec.at(j));
        ofCircle(0, -130*1.41421356, 10);
        ofPopMatrix();
    }
    
    ofSetColor(255);
    ofSetLineWidth(35);
    
    // 矢印
    for(int j=1; j<5; j++)
    {
        ofEnableAlphaBlending();
        ofSetColor(255, pos.val()*j*1.1);
       
        ofPushMatrix();
        
        // 450*800
        //ofTranslate(390-j*40, 700);
        
        // 1080*1920
        ofTranslate(950-j*80, 1750);

        ofSetLineWidth(50);
        ofLine(0, 0, 50, 50);
        ofTranslate(0, -6);
        ofLine(50, 50, 0, 100);
        ofPopMatrix();
    }
    
    ofSetColor(255);
    
    // 残りの重さ
    int val = 32-32*pos.val()/360;
    string str = "-" + ofToString(val);
    if(val<10){
        font.drawString(str, 670, 1480);
    }else{
        font.drawString(str, 620, 1480);
    }
}

void Measure3::mousePressed(int x, int y, int button)
{
    pos = f;
	changeState("Mission1");
}

string Measure3::getName()
{
	return "Measure3";
}