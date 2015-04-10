//
//  Path.h
//  CS372-CPS
//
//  Created by Will Fisher on 4/9/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#ifndef __CS372_CPS__Path__
#define __CS372_CPS__Path__

#include <memory>
#include "Shape.h"
#include "Postscript.h"
#include "NullPostscript.h"

class Path : public Postscript
{
public:
    Path(): _item(std::make_shared<NullPostscript>()) {}
    Path(std::shared_ptr<Postscript> item): _item(item) {}
    const string buildPS() override;
private:
    std::shared_ptr<Postscript> _item;
};

#endif /* defined(__CS372_CPS__Path__) */
