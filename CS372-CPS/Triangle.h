//
//  Triangle.h
//  CS372-CPS
//
//  Created by Will Fisher on 4/12/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#ifndef __CS372_CPS__Triangle__
#define __CS372_CPS__Triangle__

#include "Polygons.h"

class Triangle : public Polygons
{
public:
    Triangle(double sideLength): Polygons(3, sideLength) {}
};

#endif /* defined(__CS372_CPS__Triangle__) */
