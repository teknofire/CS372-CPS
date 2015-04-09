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
  SECTION( "Polygon" )
  {
    double numberOfSides = 4;
    double sideLength = 1;
    shared_ptr<Shape> squareLike = make_shared<Polygons>(numberOfSides, sideLength);
    //REQUIRE(squareLike->getBoundingBoxHeight() == 1.0);
    //REQUIRE(squareLike->getBoundingBoxWidth() == 1.0);
    //REQUIRE(squareLike->getCurrentPositionX() == .5);
    //REQUIRE(squareLike->getCurrentPositionY() == .5);
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
