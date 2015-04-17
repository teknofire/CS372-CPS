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

void DrawShape::setColor(double red, double green, double blue)
{
    std::stringstream buffer;
    
    buffer.precision(1);
    buffer << red / 255 << " " << green / 255 << " " << blue / 255;

    _drawColor = buffer.str();
}

void DrawShape::setDrawType(std::string type)
{
    _drawType = type;
}

void DrawShape::setRandomColor()
{
    std::mt19937::result_type seed = std::mt19937::result_type(time(0));
    auto rand_color = std::bind(std::uniform_int_distribution<int>(0,255),
                                 std::mt19937(seed));
    setColor(rand_color(), rand_color(), rand_color());
}

std::string DrawShape::buildPS()
{
    return _drawColor + " setrgbcolor\n" + _drawType + "\n";
}


