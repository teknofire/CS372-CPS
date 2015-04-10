//
//  Path.cpp
//  CS372-CPS
//
//  Created by Will Fisher on 4/9/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#include "Path.h"

const string Path::buildPS()
{
    std::stringstream buff;
    
    buff << "gsave\nnewpath\n";
    
    buff << _item->buildPS();
    
    buff << "grestore\n";
    
    return buff.str();
}