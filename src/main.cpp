#include "ofMain.h"
#include "testApp.h"

//========================================================================
int main( ){
    
    // 450*800
	ofSetupOpenGL(450,800,OF_WINDOW);			// <-------- setup the GL context
    //ofSetupOpenGL(1080,1920,OF_WINDOW);			// <-------- setup the GL context

    // 1080*1920
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new testApp());

}
