#include "ofMain.h"
#include "testApp.h"

//========================================================================
int main( ){

    int w = 16;
    int h = w;
	ofSetupOpenGL(w * 40, h * 30, OF_WINDOW);			// (640,480) <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new testApp());

}
