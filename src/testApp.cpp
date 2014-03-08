#include "testApp.h"
#include "Start.h"
#include "Scan.h"
#include "Flight.h"
#include "Measure1.h"
#include "Measure2.h"
#include "Measure3.h"
#include "Mission1.h"
#include "Mission2.h"
#include "Print.h"
#include "End.h"

//--------------------------------------------------------------
void testApp::setup(){
    
	// setup shared data
	stateMachine.getSharedData().counter = 0;
	stateMachine.getSharedData().lastUpdate = ofGetElapsedTimeMillis();
	stateMachine.getSharedData().font.loadFont("font/avenir-next-medium-sc-latin-1.ttf", 50);
	
	// initialise state machine
	stateMachine.addState<Start>();
    stateMachine.addState<Scan>();
	stateMachine.addState<Flight>();
    stateMachine.addState<Measure1>();
    stateMachine.addState<Measure2>();
    stateMachine.addState<Measure3>();
    stateMachine.addState<Mission1>();
    stateMachine.addState<Mission2>();
    stateMachine.addState<Print>();
    stateMachine.addState<End>();
    
	stateMachine.changeState("Start");
    
    //ofToggleFullscreen();
    
    _frame = 0;
}

//--------------------------------------------------------------
void testApp::update(){
//    string filename = "output/" + ofToString(_frame) + ".jpg";
//    grabbedImage.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
//    grabbedImage.saveImage(filename);
//    _frame++;
}

//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key) {
        case 'f':
            ofToggleFullscreen();
            break;
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
