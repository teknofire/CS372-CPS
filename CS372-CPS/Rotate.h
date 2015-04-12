//
//  Rotate.h
//  CS372-CPS
//
//  Created by Will Fisher on 4/12/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#ifndef __CS372_CPS__Rotate__
#define __CS372_CPS__Rotate__

#include "Shape.h"
#include <sstream>
#include <memory>
using std::shared_ptr;


class Rotate : public Shape
{
public:
    Rotate(shared_ptr<Shape> shape, double angle): _shape(shape), _angle(angle) {}

    virtual double getBoundingBoxHeight() override;
    virtual double getBoundingBoxWidth() override;
    virtual double getCurrentPositionX() override;
    virtual double getCurrentPositionY() override;

    virtual const string buildPS() override;
private:
    shared_ptr<Shape> _shape;
    double _angle;
};

#endif /* defined(__CS372_CPS__Rotate__) */
