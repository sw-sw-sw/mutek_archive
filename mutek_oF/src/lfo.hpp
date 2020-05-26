//
//  lfo.hpp
//  particle VJ
//
//  Created by nobumichi asai on 2017/10/04.
//
//

#ifndef lfo_hpp
#define lfo_hpp

#include "ofMain.h"
#include <stdio.h>

#endif /* lfo_hpp */


class Lfo {
    public:
    
    float min;
    float* max;
    float* speed;
    float theata=0;
    
    float lfo_val();
    void set_lfo(float _min,float *_max,float *_speed );
    void update_lfo();

};

