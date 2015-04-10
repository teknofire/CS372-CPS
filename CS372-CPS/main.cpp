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
#include "Polygons.h"
#include "Path.h"
#include "Page.h"
#include <memory>

using std::shared_ptr;
using std::make_shared;

int main() {
    double radius = 100;
    shared_ptr<Shape> circle = make_shared<Circle>(radius);
    shared_ptr<Shape> square = make_shared<Polygons>(5, 72);
    shared_ptr<Path> path1 = make_shared<Path>(square);
    shared_ptr<Path> path2 = make_shared<Path>(circle);
    
    Page page(path1);
    
    
    std::fstream fp("/Users/wfisher/Desktop/output.ps", std::fstream::out);
    fp << "200 200 translate\n";
    fp << path2->buildPS();
    page.createPS(fp);
    
    fp.close();
    return 0;
}
