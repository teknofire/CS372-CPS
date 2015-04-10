//
//  main.cpp
//  CS372-CPS
//
//  Created by Will Fisher on 4/6/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Circle.h"
#include <memory>

using std::shared_ptr;
using std::make_shared;

int main() {
    
    double radius = 100;
    shared_ptr<Shape> circle = make_shared<Circle>(radius);
    std::fstream fs("/Users/test/Desktop/Circle.ps", std::fstream::out);
    
    circle->createPS(fs);
    return 0;
}
