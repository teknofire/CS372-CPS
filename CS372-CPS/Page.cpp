//
//  Page.cpp
//  CS372-CPS
//
//  Created by Will Fisher on 4/9/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#include "Page.h"
#include <fstream>

const string Page::buildPS()
{
    std::stringstream buff;
    
    if (_item != nullptr)
        buff << _item->buildPS();
    
    buff << "showpage\n";
    
    return buff.str();
}

void Page::createPS(std::iostream & fp)
{
    fp << buildPS();
}