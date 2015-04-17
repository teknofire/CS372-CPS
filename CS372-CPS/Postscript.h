//
//  Postscript.h
//  CS372-CPS
//
//  Created by Will Fisher on 4/9/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#ifndef __CS372_CPS__Postscript__
#define __CS372_CPS__Postscript__

#include <string>
using std::string;

class Postscript
{
public:
    virtual ~Postscript() = default;
    virtual const string buildPS() = 0;
private:
    
};

#endif /* defined(__CS372_CPS__Postscript__) */
