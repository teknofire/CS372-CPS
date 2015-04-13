//
//  Horizontal.h
//  CS372-CPS
//
//  Created by Jacob McKenna on 4/12/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#ifndef __CS372_CPS__Horizontal__
#define __CS372_CPS__Horizontal__

#include "Shape.h"
#include <memory>
#include <vector>

using std::vector;
using std::shared_ptr;

class Horizontal : public Shape {
public:
    
    Horizontal(const vector<shared_ptr<Shape>> & shapes): _shapes(shapes)
    {}
    
    virtual double getBoundingBoxHeight() override;
    virtual double getBoundingBoxWidth() override;
    virtual double getCurrentPositionX() override;
    virtual double getCurrentPositionY() override;
    
    virtual const string buildPS() override;
    
private:
    vector<shared_ptr<Shape>> _shapes;
    
    
};

#endif /* defined(__CS372_CPS__Horizontal__) */
