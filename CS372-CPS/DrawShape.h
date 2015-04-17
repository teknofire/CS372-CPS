//
//  DrawShape.h
//  CS372-CPS
//
//  Created by Will Fisher on 4/16/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#ifndef __CS372_CPS__DrawShape__
#define __CS372_CPS__DrawShape__

#include <string>
#include <random>

class DrawShape
{
public:
    DrawShape() = default;
    DrawShape(std::string drawType, std::string drawColor): _drawType(drawType), _drawColor(drawColor) {}
    
    void setColor(double red, double green, double blue);
    void setRandomColor();
    void enableRandomColor();
    void disableRandomColor();
    void setDrawType(std::string);
    
    std::string buildPS();
    
private:
    std::string _drawType = "stroke";
    std::string _drawColor = "0 0 0";
    bool _enableRandomColor = false;
    
    typedef std::minstd_rand                                Engine;
    typedef std::uniform_real_distribution<double>          Distribution;
    
    std::function<double()> _genColor = std::bind(Distribution(0, 255), Engine((std::minstd_rand::result_type)time(NULL)));
};

#endif /* defined(__CS372_CPS__DrawShape__) */
