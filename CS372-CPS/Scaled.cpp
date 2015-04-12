//
//  Scaled.cpp
//  CS372-CPS
//
//  Created by Jacob McKenna on 4/12/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#include "Scaled.h"

double Scaled::getBoundingBoxHeight(){
    
    return _shape->getBoundingBoxHeight() * _fy;
    
}

double Scaled::getBoundingBoxWidth(){
    
    return _shape->getBoundingBoxWidth() * _fx;
    
}

double Scaled::getCurrentPositionX(){

    return getBoundingBoxWidth() / 2;
    
}

double Scaled::getCurrentPositionY(){

    return getBoundingBoxHeight() / 2;

}

const string Scaled::buildPS(){

    std::stringstream buff;
    buff << _fx << " " << _fy << " scale\n";
    buff << _shape->buildPS();
    
    return buff.str();
}
