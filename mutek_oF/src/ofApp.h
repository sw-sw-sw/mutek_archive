#pragma once

#include "ofMain.h"
#include "particle.hpp"
#include "ofxOsc.h"
#include "lfo.hpp"
#include "ofxSyphon.h"

#define NUMBER 1000000
#define RADIUS 2000
#define PORT 8000

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    //----------class set------------

    ofVbo vbo;
    ofxOscReceiver receiver;
    ofxSyphonServer mSyphonServer;

    //----------parameter set------------
    
    Particle ptcl[NUMBER];
    ofVec3f verts[NUMBER];
    
    int NUM = NUMBER; // number
    int _NUM = NUM*0.6; // tmp number
    int counter=0;
    
    float R =RADIUS; // visualize area
    float _R =1000.; // temp visualize area
    
    float depth=0; // depth
    float _depth=0; // temp depth

    float  RotX=100; // rotation
    float _RotX=100; // temp rotation

    float  RotY=700; // rotation
    float _RotY=700; // temp rotation
    
    float fase=100;
    float _fase=100;
    float __fase=100;


    float _a=0.008;  // rate
    
    int alpha=255.;  // alpha
    int _alpha=255;  // alpha
 
    int   fade=50; // fade
    int   _fade=50; // temp fade

    float posr=0.433071;
    float _posr=posr;
    
    float fff = 3.782047;
    float _fff = fff;

    float self_rotation=0.0;
    float _self_rotation=0.047;
    
    Lfo lfo0;
    float lfo_speed=0.01;
    float _lfo_speed=lfo_speed;
    float lfo_max=20.;
    float _lfo_max=20.;

    
};
