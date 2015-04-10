//
//  NoPostscript.h
//  CS372-CPS
//
//  Created by Will Fisher on 4/10/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#ifndef __CS372_CPS__NoPostscript__
#define __CS372_CPS__NoPostscript__

#include "Postscript.h"

class NullPostscript : public Postscript
{
public:
    const string buildPS() override;

};

#endif /* defined(__CS372_CPS__NoPostscript__) */
