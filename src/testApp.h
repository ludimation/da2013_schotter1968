#pragma once

#include "ofMain.h"

class mySquare {
public:
    int     x,y,rZ, r,g,b;
    
};

class testApp : public ofBaseApp{    
public:
    void    setup();
    void    update();
    void    draw();
    
    void    keyPressed(int key);
    void    keyReleased(int key);
    void    mouseMoved(int x, int y);
    void    mouseDragged(int x, int y, int button);
    void    mousePressed(int x, int y, int button);
    void    mouseReleased(int x, int y, int button);
    void    windowResized(int w, int h);
    void    dragEvent(ofDragInfo dragInfo);
    void    gotMessage(ofMessage msg);
    
    void    buildSquares();
    void    updateDrawing();
    
    int     drawingCount;
    vector  <mySquare> squares;
    int     waitMillis;
    int     waitMod;

    int     w;
    int     h;

    ofTrueTypeFont  myFont;
};
