#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(ofColor::white);       // set bakcground color of piece to white
	ofNoFill();                         // draw empty shapes
	ofSetColor(ofColor::black);         // use black as stroke color
	ofSetFrameRate(1);                 // slow down draw function a bit (default is 60fps?)
	ofSetRectMode(OF_RECTMODE_CENTER);  // set rect mode to draw rectangles from center of object
    
    // TO DO - add signature and citation of original work "###/° | david_allen_2013 ("Georg Nees - Schotter 1968")"
    ///////////////
	//old OF default is 96 - but this results in fonts looking larger than in other programs. 
	ofTrueTypeFont::setGlobalDpi(72);
    ofSeedRandom(19800512);
    ofResetElapsedTimeCounter();
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::buildSquares(){
    squares.clear();

    // build the array of squares one row at a time
    for (int j = 0; j < 22; j++) { // Columns
        for (int i = 0; i < 12; i++) { // Rows have priority
            mySquare s = mySquare();
            
            // size and location of squares
            int w = 16; //size of squares
            int h = w;
            float marginX = w * 14.5; // expressed in multiples of square
            float marginY = h * 3.5;
            float gridX = w * i + marginX; // where square would line up with grid
            float gridY = h * j + marginY;
            float randX = ofRandomf(); // random offsets
            float randY = ofRandomf();
            s.x = gridX + (j/2.0) * randX; // calculated random positions
            s.y = gridY + (j/2.0) * randY;
            
            // rotation of squares
            float randA = ofRandomf();
            s.rZ = j * 2.0 * randA;
            
            // color of squares based on x, y, and a offsets relative to the square grid
            s.r = abs(256 * randX * j/11.0);
            s.g = abs(256 * randY * j/11.0);
            s.b = abs(256 * randA * j/11.0);
            
            squares.push_back(s);
        }
    }    
}

//--------------------------------------------------------------
void testApp::draw(){

//*  // only update the screen up to 1024 frames
    if (ofGetFrameNum() <= 1023) {
        
        // buildSquares vector
        buildSquares();
        
        // draw the pre-built array of squares one row at a time
        for (int i = 0; i < squares.size(); i++) {
            int w = 16; //size of squares
            int h = w;
            
            ofSetColor(squares[i].r, squares[i].g, squares[i].b);
            
            // position and draw the squares themselves
            ofPushMatrix();         // push the current coordinate position
            ofTranslate(squares[i].x, squares[i].y, 0);   // move the current coordinate system to (x,y) and make that zero
            ofPushMatrix();         // push the current coordinate position
            ofRotateZ(squares[i].rZ);           // rotate the coordinate system
            ofRect(0, 0, w, h);     // draw a rect at (0,0)
            ofPopMatrix();          // recall the pushed coordinate position
            ofPopMatrix();          // recall the pushed coordinate position        
        }
        
        // print a title
        int w = 16;
        int h = w;   
        ofSetColor(ofColor::black);         // use black as text color
        ofTrueTypeFont  myFont;
        myFont.loadFont("verdana.ttf", w/2, true, true);
        myFont.setLineHeight(18.0f);
        myFont.setLetterSpacing(1.037);
        string title = "da_2013(\"Schotter 1968\") | f.";
        title.append(ofToString(ofGetFrameNum())); 
        //title.append(" / °");
        myFont.drawString(title, w * 14, h * 26.5);
        //    ofSetWindowTitle(title);

        // Handle framerates and pausing at beginning and end
        if (ofGetFrameNum() == 0) {
        } else if (ofGetFrameNum() == 1) {
            // pause for 5 seconds on the first frame
            while (ofGetElapsedTimeMillis() <5000){
                // print something to let me know I'm in a loop
            }
            
            // ofSleepMillis(5000);
        } else if (ofGetFrameNum() > 1 && ofGetFrameNum() < 1023 ) {
            // set the frame rate to increase as frame count approaches 512
            // then decrease as frane count approaches 1024
            int r = 512 - abs(512-ofGetFrameNum());
            ofSetFrameRate(r);
        } else if (ofGetFrameNum() == 1023) {
            // disable clearing the frame on the next frame
            ofSetBackgroundAuto(false);
        } 
        ofResetElapsedTimeCounter();
    }
//*/
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == 's') {
        ofSaveScreen("test_"+ofToString(ofGetFrameNum())+".png");
    }
    if (key == 'b') {
        buildSquares();
    }
        
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    buildSquares();
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