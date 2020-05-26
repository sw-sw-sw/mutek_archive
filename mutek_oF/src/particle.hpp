//
//  perticle.hpp
//  RadioactiveVisualiser
//
//  Created by nobumichi asai on 2017/04/27.
//
//



#include <stdio.h>
#include "ofMain.h"


class Particle {
public:
    
    ofVec3f* pos; //particle's position
    float   posR; //Rotate Position 0-360
    
    float*  p_R;
    int*    p_NUM;
    float*  p_depth;
    int*    p_counter;
    float*  p_fase;
    float*  p_rate;
    float*  p_fff;
    float*  p_posr;
    float*  p_alpha;
    int     z_depth;

    void    draw();
    void    update();

    void    setup( int* _counter,int* _NUM, float* _R,float* _depth,float* _fase,float* _fff,float* _posr);

};


