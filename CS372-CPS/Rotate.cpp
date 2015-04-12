//
//  Rotate.cpp
//  CS372-CPS
//
//  Created by Will Fisher on 4/12/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#include "Rotate.h"

const string Rotate::buildPS()
{
    std::stringstream buff;
    buff << _angle << " rotate\n";
    buff << _shape->buildPS();
    
    return buff.str();
}

double Rotate::getBoundingBoxHeight() {
    if (_angle == 90 || _angle == 270)
        return _shape->getBoundingBoxWidth();
    else
        return _shape->getBoundingBoxHeight();
}
double Rotate::getBoundingBoxWidth() {
    if (_angle == 90 || _angle == 270)
        return _shape->getBoundingBoxHeight();
    else
        return _shape->getBoundingBoxWidth();
}
double Rotate::getCurrentPositionX() {
    if (_angle == 90 || _angle == 270)
        return _shape->getCurrentPositionY();
    else
        return _shape->getCurrentPositionX();
}
double Rotate::getCurrentPositionY() {
    if (_angle == 90 || _angle == 270)
        return _shape->getCurrentPositionX();
    else
        return _shape->getCurrentPositionY();
}