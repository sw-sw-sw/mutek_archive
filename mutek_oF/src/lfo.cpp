//
//  lfo.cpp
//  particle VJ
//
//  Created by nobumichi asai on 2017/10/04.
//
//

#include "lfo.hpp"



float Lfo::lfo_val(){
    theata += *speed;
//    return ofMap(sin(ofGetElapsedTimef()*speed),-1,1,min,max);
    return ofMap(sin(theata),-1,1,min,*max);

}


void Lfo::set_lfo(float _min,float *_max,float *_speed){
    min = _min;
    max = _max;
    speed = _speed;
}


void Lfo::update_lfo(){
    theata += *speed;
    if(theata>360){
        theata = 0;
    }
};
