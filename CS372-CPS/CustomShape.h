//
//  CustomShape.h
//  CS372-CPS
//
//  Created by Jacob McKenna on 4/13/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#ifndef __CS372_CPS__CustomShape__
#define __CS372_CPS__CustomShape__
#include "Shape.h"

class CustomShape : public Shape {
public:
    
    CustomShape();
    
    virtual double getBoundingBoxHeight() override;
    virtual double getBoundingBoxWidth() override;
    virtual double getCurrentPositionX() override;
    virtual double getCurrentPositionY() override;
    
    virtual const string buildPS() override;
    
private:
    
    
    
};
#endif /* defined(__CS372_CPS__CustomShape__) */
