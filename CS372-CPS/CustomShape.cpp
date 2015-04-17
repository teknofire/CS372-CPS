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
#include "Rotate.h"

#include <iostream>
#include <sstream>
#include <initializer_list>
#include <memory>
#include <vector>
#include <random>

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

CustomShape::CustomShape(int firstOrbit, int numberPlanets):_shapes({})
{
    auto otherOrbit = firstOrbit / 2;
    auto planetSize = otherOrbit / 2;
    
    shared_ptr<Shape> planet = make_shared<Circle>(planetSize);
    planet->getDrawShape()->setDrawType("fill");
    
    shared_ptr<Shape> spacer1 = make_shared<Spacer>(firstOrbit*2 - planetSize*2, firstOrbit*2 - planetSize*2);
    shared_ptr<Shape> spacer2 = make_shared<Spacer>(otherOrbit, otherOrbit);
    
    std::mt19937::result_type seed = std::mt19937::result_type(time(0));
    auto orientation = std::bind(std::uniform_int_distribution<int>(0,360),
                                 std::mt19937(seed));
    
//    std::mt19937 generator(time(0));
//    std::uniform_int_distribution<int> distribution(0,360);
//    auto orientation = std::bind ( distribution, generator );
    
    for(auto ii=0; ii<numberPlanets; ++ii)
    {
        shared_ptr<Shape> orbit = make_shared<Circle>(firstOrbit + (ii*otherOrbit));
        _shapes.push_back(orbit);
        
        shared_ptr<Vertical> aPlanet = make_shared<Vertical>(std::initializer_list<shared_ptr<Shape>>({ spacer1 }));
        
        for(auto jj=0; jj<=ii-1; ++jj)
            aPlanet->push_back(spacer2);
        
        planet->getDrawShape()->setRandomColor();
        aPlanet->push_back(planet);
        shared_ptr<Rotate> rotated = make_shared<Rotate>(aPlanet, orientation());
        
        _shapes.push_back(rotated);
    }
}

const string CustomShape::buildPS() {
    std::stringstream buff;
    
    for (auto shape : _shapes){
        buff << shape->buildPS();
    }
    
    return buff.str();
    
}