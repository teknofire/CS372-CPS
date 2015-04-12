//
//  Square.h
//  CS372-CPS
//
//  Created by Will Fisher on 4/12/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#ifndef __CS372_CPS__Square__
#define __CS372_CPS__Square__

#include "Polygons.h"

class Square : public Polygons
{
public:
    Square(double sideLength): Polygons(4, sideLength) {}
};

#endif /* defined(__CS372_CPS__Square__) */
