//
//  Particle.cpp
//  Particles5
//
//  Created by Senaga Takahisa on 2015/06/25.
//
//

#include "Particle.h"
#include "ofMain.h"

void Particle::setSpeed(int x, int y, bool isMouse){
    if (isMouse) {
        speed_x =(x -loc_x) /8.0;
        speed_y =(y -loc_y) /8.0;
    }
    
    loc_x =loc_x +speed_x;
    loc_y =loc_y +speed_y;
    
    if (loc_x<0){
        speed_x =speed_x * -1;
    }
    
    if (loc_x>ofGetWidth()){
        speed_x =speed_x * -1;
    }
    
    if (loc_y<0){
        speed_y =speed_y * -1;
    }
    
    if (loc_y>ofGetHeight()){
        speed_y =speed_y * -1;
    }
    
    
}