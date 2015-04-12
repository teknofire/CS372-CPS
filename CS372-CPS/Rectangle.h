//
//  Rectangle.h
//  CS372-CPS
//
//  Created by Will Fisher on 4/12/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#ifndef __CS372_CPS__Rectangle__
#define __CS372_CPS__Rectangle__


#include "Shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(double widthLength, double heightLength);
    virtual double getBoundingBoxHeight() override;
    virtual double getBoundingBoxWidth() override;
    virtual double getCurrentPositionX() override;
    virtual double getCurrentPositionY() override;
    virtual const string buildPS() override;
protected:
private:
    double _widthLength;
    double _heightLength;
};

#endif /* defined(__CS372_CPS__Rectangle__) */
