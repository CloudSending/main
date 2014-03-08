//
//  Measure2.cpp
//  cloudSending
//
//  Created by NAOYAIWAMOTO on 2014/03/05.
//
//

#include "Measure2.h"

void Measure2::setup()
{
    // img
    img.loadImage("Measure2/img/0303-re_date03.png");
    longImg.loadImage("Measure2/img/longimage3.png");
    
    // アニメーション
    value = 28;
    getSharedData().weight = value;
    

	f.animateFromTo( 0, value ); //suitcase
	f.setDuration(2);
	f.setRepeatType( PLAY_ONCE ); //PLAY_ONCE
    pos = f;
    AnimCurve curve;
    curve = (AnimCurve) (EASE_IN_EASE_OUT);
    pos.setCurve( curve );
    curveNames = ofxAnimatable::getCurveName( curve );
    
    // font
    font.loadFont("font/BebasNeue.otf", 180);
    font2.loadFont("font/avenir-next-medium-sc-latin-1.ttf", 110);
}

void Measure2::update()
{
    float dt = 1.0f / ofGetFrameRate();
    pos.update( dt );
}

void Measure2::draw()
{
    
    ofSetColor(255);
    longImg.draw(0, -1990+60*pos.val());
    //longImg.draw(0, -2200+25*pos.val());
    
    // white back
    //ofRect(220, 1470, 640, -880);
    //ofRect(90, 600, 270, -350);
    ofSetColor(0.0, 0.0, 200);
    
    // 360:x = 32:pos.val();
    int x = 360*pos.val()/32;
    
    // blue
    //ofRect(90, 610, 270, - x); //
    ofRect(220, 1470, 640, - pos.val()*27.1); //
    //ofRect(216, 610, 660, - pos.val()*3.6); //
    
    // 画像を描画
    ofEnableAlphaBlending();
    ofSetColor(255);
    img.resize(ofGetWidth(), ofGetHeight());
    img.draw(0, 0);
    ofDisableAlphaBlending();
    
    // number
    if(pos.hasFinishedAnimating() == true)
    {
        ofSetColor(255,75,145);
    }else{
        ofSetColor(190);
    }
    
    //font.drawString(ofToString((int)((pos.val())*32/100)), 190, 530);
    
    // 現在の重さ
    if(pos.val()<10)
        font.drawString(ofToString((int)pos.val()), 450, 1000);
    else
        font.drawString(ofToString((int)pos.val()), 380, 1000);

    // 残りの重さ
    int num = 32-pos.val();
    if (num<9) {
        font2.drawString(ofToString(num), 480, 1760);
    }else{
        font2.drawString(ofToString(num), 420, 1760);
    }
}

void Measure2::mousePressed(int x, int y, int button)
{
    pos = f;
	changeState("Measure3");
}

//--------------------------------------------------------------
void Measure2::keyPressed(int key){
    switch (key) {
        case 'a':
            changeState("Measure1");
            break;
            
        case 's':
            changeState("Measure3");            
            break;
        default:
            break;
    }
}



string Measure2::getName()
{
	return "Measure2";
}