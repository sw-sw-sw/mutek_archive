//
//  perticle.cpp
//  MUTEK HAIS NOI
//
//  Created by nobumichi asai on 2017/11/02.
//
//

#include "particle.hpp"


void Particle::draw(){
}

void Particle::update(){
    
        float _rate =(float)*p_counter/(float)*p_NUM;
   
    posR = (*p_counter % 36000)/ *p_posr;

        pos->x = sin(posR * *p_fff) * (*p_R) * _rate + sin(*p_counter) * *p_fase;
        pos->y = cos(posR * *p_fff) * (*p_R) * _rate + cos(*p_counter) * *p_fase;
    
//    pos->x = sin(posR * *p_fff) * (*p_R) * _rate + sin(*p_counter) * *p_fase;
//    pos->y = cos(posR * *p_fff) * (*p_R) * _rate + cos(*p_counter) * *p_fase;
    
        z_depth +=200;
        if(z_depth>10000){z_depth=0;}
        pos->z = z_depth* *p_depth;
}


void Particle::setup(int* _counter,int* _NUM, float* _R,float* _depth,float* _fase,float* _fff,float* _posr){
    
    p_counter=_counter;
    p_R=_R;
    p_NUM=_NUM;
    p_depth=_depth;
    p_fase =_fase;
    p_fff=_fff;
    p_posr=_posr;
    
    float _rate =(float)*p_counter/(float)*p_NUM;
    posR = (*p_counter % 36000)/102.;
    pos->x = sin(posR) * (*p_R) * _rate;
    pos->y = cos(posR) * (*p_R) * _rate;
    
    z_depth = ofRandom(100000);
    pos->z = z_depth;
    
}
