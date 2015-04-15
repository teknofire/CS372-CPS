//
//  CustomShape.cpp
//  CS372-CPS
//
//  Created by Jacob McKenna on 4/13/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#include "Shape.h"
#include "CustomShape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Polygons.h"
#include "Circle.h"
#include "Path.h"
#include "Spacer.h"
#include "Vertical.h"

#include <iostream>
#include <sstream>
#include <initializer_list>
#include <memory>
#include <vector>
using std::make_shared;

//double getBoundingBoxHeight() {
//    
//    return 0;
//    
//}
//double getBoundingBoxWidth() {
//    
//    return 0;
//    
//}
//double getCurrentPositionX() {
//    
//    return 0;
//    
//}
//double getCurrentPositionY() {
//    
//    return 0;
//    
//}

CustomShape::CustomShape():_shapes({})
{
    shared_ptr<Shape> planet = make_shared<Circle>(10);
    shared_ptr<Shape> spacer1 = make_shared<Spacer>(140, 140);
    shared_ptr<Shape> spacer2 = make_shared<Spacer>(20, 20);
    shared_ptr<Shape> circle = make_shared<Circle>(80);
    shared_ptr<Shape> circle2 = make_shared<Circle>(120);
    shared_ptr<Shape> circle3 = make_shared<Circle>(160);
    shared_ptr<Shape> orbits = make_shared<Layered>(std::initializer_list<shared_ptr<Shape>>({ circle3, circle2, circle}));
    
    shared_ptr<Shape> planet1 = make_shared<Vertical>(std::initializer_list<shared_ptr<Shape>>({ spacer1, planet, spacer2, planet, spacer2, planet }));
    
    _shapes.push_back(orbits);
    _shapes.push_back(planet1);
}

const string CustomShape::buildPS() {
    std::stringstream buff;
    
    for (auto shape : _shapes){
        buff << shape->buildPS();
    }
    
    return buff.str();
    
}