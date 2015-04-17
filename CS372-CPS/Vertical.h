//
//  Vertical.h
//  CS372-CPS
//
//  Created by Jacob McKenna on 4/12/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#ifndef __CS372_CPS__Vertical__
#define __CS372_CPS__Vertical__

#include "Shape.h"
#include <memory>
#include <vector>

using std::vector;
using std::shared_ptr;

class Vertical : public Shape {
public:
    
    Vertical(const vector<shared_ptr<Shape>> & shapes): _shapes(shapes)
    {}
    
    virtual double getBoundingBoxHeight() override;
    virtual double getBoundingBoxWidth() override;
    virtual double getCurrentPositionX() override;
    virtual double getCurrentPositionY() override;
    
    virtual const string buildPS() override;
    
    void push_back(shared_ptr<Shape>);
    
private:
    vector<shared_ptr<Shape>> _shapes;
    
    
};
#endif /* defined(__CS372_CPS__Vertical__) */
