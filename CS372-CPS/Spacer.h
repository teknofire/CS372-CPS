//
//  Spacer.h
//  CS372-CPS
//
//  Created by Will Fisher on 4/12/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#ifndef __CS372_CPS__Spacer__
#define __CS372_CPS__Spacer__

#include <stdio.h>
#include "Rectangle.h"

class Spacer:public Rectangle
{
    public:
    
    Spacer(double widthLength, double heightLength):Rectangle(widthLength,heightLength)
    {
        
    }

    virtual const string buildPS() override
    {
        return "";
    }
};

#endif /* defined(__CS372_CPS__Spacer__) */
