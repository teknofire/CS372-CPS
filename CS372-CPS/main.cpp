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
#include "Square.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Rotate.h"
#include "Scaled.h"
#include "Layered.h"
#include "Vertical.h"
#include "Horizontal.h"
#include "Spacer.h"
#include "CustomShape.h"
#include <memory>
#include <initializer_list>

using std::shared_ptr;
using std::make_shared;

int main() {
    double radius = 100;
    
    shared_ptr<Shape> circle = make_shared<Circle>(radius);
    shared_ptr<Shape> center = make_shared<Circle>(1);
    shared_ptr<Shape> pentagon = make_shared<Polygons>(5, 72);
    shared_ptr<Shape> bounds = make_shared<Square>(pentagon->getBoundingBoxHeight());
    shared_ptr<Shape> triangle = make_shared<Triangle>(72);
    shared_ptr<Shape> rectangle = make_shared<Rectangle>(pentagon->getBoundingBoxWidth(), pentagon->getBoundingBoxHeight());
    
    shared_ptr<Path> trianglePath = make_shared<Path>(triangle);
    shared_ptr<Path> pentagonPath = make_shared<Path>(pentagon);
    shared_ptr<Path> circlePath = make_shared<Path>(circle);
    shared_ptr<Path> boundsPath = make_shared<Path>(bounds);
    shared_ptr<Path> centerPath = make_shared<Path>(center);
    shared_ptr<Path> rectanglePath = make_shared<Path>(rectangle);
    
    
    shared_ptr<Rotate> rotatedPentagon = make_shared<Rotate>(pentagon, 180);
    shared_ptr<Path> rotatedPentagonPath = make_shared<Path>(rotatedPentagon);
    
    shared_ptr<Scaled> scaledTriangle = make_shared<Scaled>(triangle, 5, 5);
    shared_ptr<Path> scaledTrianglePath = make_shared<Path>(scaledTriangle);
    
    shared_ptr<Layered> layer = make_shared<Layered>(std::initializer_list<shared_ptr<Shape>>({triangle, rectangle, circle}));
    
    shared_ptr<Vertical> vert = make_shared<Vertical>(std::initializer_list<shared_ptr<Shape>>({triangle, rectangle, circle}));
    shared_ptr<Horizontal> horizontal = make_shared<Horizontal>(std::initializer_list<shared_ptr<Shape>>({triangle, rectangle, circle}));
    
    shared_ptr<Shape> spacer = make_shared<Spacer>(pentagon->getBoundingBoxWidth(), pentagon->getBoundingBoxHeight());
    shared_ptr<Vertical> vert2 = make_shared<Vertical>(std::vector<shared_ptr<Shape>>{triangle, spacer, circle});
    
    
//    Page page(path1);
    
    std::fstream fp("output.ps", std::fstream::out);
    fp << "200 200 translate\n";
    fp << pentagonPath->buildPS();
    fp << circlePath->buildPS();
    fp << boundsPath->buildPS();
    fp << centerPath->buildPS();
    fp << trianglePath->buildPS();
    fp << rectanglePath->buildPS();
    fp << rotatedPentagonPath->buildPS();
    fp << scaledTrianglePath->buildPS();
    fp << "showpage\n";
    
    fp << "200 200 translate\n";
    fp << layer->buildPS();
    fp << "showpage\n";
    
    fp << "200 200 translate\n";
    fp << vert->buildPS();
    fp << "showpage\n";
    
    fp << "200 200 translate\n";
    fp << vert2->buildPS();
    fp << "showpage\n";
    
    fp << "200 200 translate\n";
    fp << horizontal->buildPS();
    fp << "showpage\n";
    
    CustomShape ourshape(20, 10);
    
    fp << "200 200 translate\n";
    fp << ourshape.buildPS();
    fp << "showpage\n";
//    page.createPS(fp);
    
    fp.close();
    
    
    
    return 0;
}
