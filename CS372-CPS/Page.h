//
//  Page.h
//  CS372-CPS
//
//  Created by Will Fisher on 4/9/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#ifndef __CS372_CPS__Page__
#define __CS372_CPS__Page__

#include <memory>
using std::shared_ptr;
#include <string>
#include <sstream>

#include "Postscript.h"
#include "Shape.h"

class Page : public Postscript
{
public:
    Page(): _item(nullptr) {}
    Page(shared_ptr<Postscript> item): _item(item) {}
    const string buildPS() override;
    void createPS(std::iostream &);
private:
    shared_ptr<Postscript> _item;
};

#endif /* defined(__CS372_CPS__Page__) */
