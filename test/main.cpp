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
    shared_ptr<Shape> square = make_shared<Polygons>(numberOfSides, sideLength);
    REQUIRE(square->getBoundingBoxHeight() == 1.0);
    REQUIRE(square->getBoundingBoxWidth() == 1.0);
    REQUIRE(square->getCurrentPositionX() == .5);
    REQUIRE(square->getCurrentPositionY() == .5);
          
    numberOfSides = 3, sideLength = 1;
      
      shared_ptr<Shape> triangle = make_shared<Polygons>(numberOfSides, sideLength);
      REQUIRE(triangle->getBoundingBoxHeight() == 1.0);
      REQUIRE(triangle->getBoundingBoxWidth() == 1.0);
      REQUIRE(triangle->getCurrentPositionX() == .5);
      REQUIRE(triangle->getCurrentPositionY() == .5);
      
      numberOfSides = 5, sideLength = 1;
      
      shared_ptr<Shape> pentagon = make_shared<Polygons>(numberOfSides, sideLength);
      //REQUIRE(pentagon-> getBoundingBoxHeight() == )
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
