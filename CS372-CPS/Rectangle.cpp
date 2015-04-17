//
//  Rectangle.cpp
//  CS372-CPS
//
//  Created by Will Fisher on 4/12/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#include "Rectangle.h"
#include <sstream>


Rectangle::Rectangle(double widthLength, double heightLength): _widthLength(widthLength), _heightLength(heightLength){}

double Rectangle::getBoundingBoxHeight()
{
    return _heightLength;
}

double Rectangle::getBoundingBoxWidth()
{
    return _widthLength;
}

double Rectangle::getCurrentPositionX()
{
    return _widthLength/2;
}

double Rectangle::getCurrentPositionY()
{
    return _heightLength/2;
}

const string Rectangle::buildPS()
{
    std::stringstream buff;
    buff << -getCurrentPositionX() << " " << -getCurrentPositionY() << " moveto\n";
    buff << _widthLength << " 0 rlineto\n";
    buff << "0 " << _heightLength << " rlineto\n";
    buff << -_widthLength << " 0 rlineto\n";
    buff << "closepath\n";
    buff << Shape::getDrawShape()->buildPS();
    
    return buff.str();
}