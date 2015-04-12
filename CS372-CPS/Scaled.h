//
//  Scaled.h
//  CS372-CPS
//
//  Created by Jacob McKenna on 4/12/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#ifndef __CS372_CPS__Scaled__
#define __CS372_CPS__Scaled__
#include "Shape.h"
#include <memory>
using std::shared_ptr;

class Scaled : public Shape
{
public:
    
    Scaled(shared_ptr<Shape> shape, double fx, double fy)
    {
    
    }
    
    virtual double getBoundingBoxHeight() override;
    virtual double getBoundingBoxWidth() override;
    virtual double getCurrentPositionX() override;
    virtual double getCurrentPositionY() override;
    virtual const string buildPS() override;
    
private:
    shared_ptr<Shape> _shape;
    double _fx;
    double _fy;
    
};

#endif /* defined(__CS372_CPS__Scaled__) */
