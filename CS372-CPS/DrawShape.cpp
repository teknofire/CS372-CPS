//
//  DrawShape.cpp
//  CS372-CPS
//
//  Created by Will Fisher on 4/16/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#include "DrawShape.h"
#include <sstream>
#include <random>
#include <iostream>

void DrawShape::setColor(double red, double green, double blue)
{
    std::stringstream buffer;
    
    buffer.precision(1);
    buffer << red / 255 << " " << green / 255 << " " << blue / 255;

    _drawColor = buffer.str();
}

void DrawShape::enableRandomColor()
{
    _enableRandomColor = true;
}
void DrawShape::disableRandomColor()
{
    _enableRandomColor = false;
}

void DrawShape::setDrawType(std::string type)
{
    _drawType = type;
}

void DrawShape::setRandomColor()
{
    if (_enableRandomColor)
    {
        setColor(_genColor(), _genColor(), _genColor());
    }
}

std::string DrawShape::buildPS()
{
    setRandomColor();
    return _drawColor + " setrgbcolor\n" + _drawType + "\n";
}


