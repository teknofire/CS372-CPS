//
//  main.cpp
//  test
//
//  Created by Will Fisher on 4/6/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//


#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Shape.h"
#include "Circle.h"
#include "Polygons.h"

#include <iostream>
#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <limits>

//Compare
bool AreSame(double a, double b) {
    return std::fabs(a - b) <= 0.0005;
}

//Test Strategy Using Catch
//Test the results from each method to determine if the shape will be built rights
//Test the output stream for proper format
//Visual Inspection of resulting file.ps
TEST_CASE( "Shapes", "[shape]")
{

    SECTION( "Circle" )
    {
        double radius = 10;
        shared_ptr<Shape> circle = make_shared<Circle>(radius);
        REQUIRE(circle->getBoundingBoxHeight() == 20);
        REQUIRE(circle->getBoundingBoxWidth() == 20);
        REQUIRE(circle->getCurrentPositionX() == 10);
        REQUIRE(circle->getCurrentPositionY() == 10);
    }
    SECTION( "4 sided polygon" )
    {
        double numberOfSides = 4;
        double sideLength = 1;
        shared_ptr<Shape> squareLike = make_shared<Polygons>(numberOfSides, sideLength);
    
        REQUIRE(AreSame(squareLike->getBoundingBoxHeight(), 1.0));
        REQUIRE(AreSame(squareLike->getBoundingBoxWidth(), 1.0));
        REQUIRE(AreSame(squareLike->getCurrentPositionX(), 0.5));
        REQUIRE(AreSame(squareLike->getCurrentPositionY(), 0.5));
    }
    
    SECTION( "Triangle" )
    {
        double numberOfSides = 3;
        double sideLength = 1;
        
        shared_ptr<Shape> triangle = make_shared<Polygons>(numberOfSides, sideLength);
        
        REQUIRE(AreSame(triangle->getBoundingBoxHeight(), .866025));
        REQUIRE(triangle->getBoundingBoxWidth() == 1.0);
        REQUIRE(triangle->getCurrentPositionX() == .5);
        REQUIRE(AreSame(triangle->getCurrentPositionY(), .866025 / 2));
        //t the
        
        
    }
    
    SECTION( "5 sided polygon" )
    {
        double numberOfSides = 5;
        double sideLength = 1;
        shared_ptr<Shape> pentagon = make_shared<Polygons>(numberOfSides, sideLength);
        
        REQUIRE(AreSame(pentagon->getBoundingBoxHeight(), 1.53884));
        REQUIRE(AreSame(pentagon->getBoundingBoxWidth(), 1.61803));
        REQUIRE(AreSame(pentagon->getCurrentPositionX(), 1.61803/2.0));
        REQUIRE(AreSame(pentagon->getCurrentPositionY(), 1.53884/2.0));
    }
//
//  SECTION( "Square" )
//  {
//    Square square(72);
//  }
//
//  Section( "Rectangle" )
//  {
//    Rectangle rectangle(72, 144);
//  }
//  Section( "Spacer" )
//  {
//    Spacer spacer(72);
//  }
}
