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
#include "Layered.h"
#include <memory>
#include <vector>

class CustomShape : public Postscript {
public:
    
    CustomShape(int, int);
    
    virtual const string buildPS() override;
    
private:
    std::vector<shared_ptr<Shape>> _shapes;
    
};
#endif /* defined(__CS372_CPS__CustomShape__) */
