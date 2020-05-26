#include "ofMain.h"
#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetCircleResolution(3);
    ofSetVerticalSync(0);
    ofSetFrameRate(60);
    ofBackground(0, 0, 0); // background color
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(false);
    receiver.setup( PORT );  //OSC setup
    
    lfo0.set_lfo(0, &lfo_max,&lfo_speed);
    
 // -------- Verts <-> pos address --------
    
    for (int i = 0 ; i < NUMBER ; i++){
        ptcl[i].pos = &verts[i];
    }
    
// -------- initial perticle --------
    
    for (counter = 0; counter < NUMBER ; counter++) {
        ptcl[counter].setup( &counter, &NUM, &R, &depth, &fase, &fff, &posr);
    }
    
    vbo.setVertexData(verts, NUM, GL_DYNAMIC_DRAW);   //vbo initialize
    
    mSyphonServer.setName("Main");      // -------- Syphon --------

}



//--------------------------------------------------------------
void ofApp::update(){

// - - - - - - - - - - update perticle  - - - - - - - - - -

        for (counter = 0; counter < NUM ; counter++) {
            ptcl[counter].update();
        }
    
        vbo.updateVertexData(verts, NUM);

//- -- - - - - - - osc receive - - - - - - - - - - -
    
    while(receiver.hasWaitingMessages()){
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        
        if (m.getAddress() == "/NUM"){ // - - - - NUM - - -
          _NUM = m.getArgAsInt32(0);
        }
        if (m.getAddress() == "/R"){// - - - - R  - - -
            _R = m.getArgAsInt32(0);
        }
        if (m.getAddress() == "/self_rot"){// - - - - self ratation - - -
            _self_rotation= m.getArgAsFloat(0);

        }
        if (m.getAddress() == "/roty"){// - - - - RotY - - -
             _RotY = m.getArgAsFloat(0);
        }
        if (m.getAddress() == "/posr"){// - - - - posr - - -
            posr = m.getArgAsFloat(0);
            }
        
        if (m.getAddress() == "/depth"){// - - - - depth - - -
            _depth = m.getArgAsFloat(0);
        }
        
        if (m.getAddress() == "/fade"){// - - - - fade - - -
            fade=_fade = m.getArgAsInt32(0)/2;

        }
        
        if (m.getAddress() == "/a"){// - - - - chage speed - - -
            _a = m.getArgAsFloat(0);
        }
        
        if (m.getAddress() == "/alpha"){// - - - - chage speed - - -
            _alpha = m.getArgAsFloat(0);
            alpha = _alpha;

        }

        if (m.getAddress() == "/fase"){// - - - - fase - - -
            _fase = m.getArgAsFloat(0);
        }
        
        if (m.getAddress() == "/fff"){// - - - - fff - - -
            fff = m.getArgAsFloat(0);
        }
        
        if (m.getAddress() == "/lfo"){// - - - - lfo speed - - -
            _lfo_speed = m.getArgAsFloat(0);

        }
        
        if (m.getAddress() == "/lfo_d"){// - - - - lfo max- - -
            _lfo_max=m.getArgAsFloat(0);
        }
    }

    
    NUM += -(NUM-_NUM)*_a; // NUMBER
    
    R += -(R-_R)*_a;  // Radius
    
    depth += -(depth-_depth)*_a; //depth
    
    self_rotation+= _self_rotation;  //self rotation
    
    lfo_speed += -(lfo_speed-_lfo_speed)*_a; // LFO SPEED
    lfo_max += -(lfo_max-_lfo_max)*_a; //LFO MAX
    
    __fase += -(__fase-_fase)*_a; //Fase
    fase = __fase+lfo0.lfo_val(); //Fase

}
//--------------------------------------------------------------
void ofApp::draw(){
    
// - - - - - - - - - - fadeout - - - - - - - - - -
    
    ofSetColor(0,0,0,fade);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());

//  - - - - - - - - - -drawing - - - - - - - - - -
    
    ofSetColor(255,255,255,alpha);

        ofPushMatrix();

            ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
            ofRotate(self_rotation, 0, 0, 1);


            glPointSize(1);
            vbo.draw(GL_POINTS, 0, NUM);

        ofPopMatrix();
    
//    mSyphonServer.publishScreen();

 }

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    
}


//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

