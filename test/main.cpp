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

#include <iostream>
#include <memory>
using std::shared_ptr;
using std::make_shared;


TEST_CASE( "Shapes", "[shape]")
{

  SECTION( "circle" )
  {
    shared_ptr<Shape> circle = make_shared<Circle>(10);
    REQUIRE(circle->getBoundingBoxHeight() == 20);
    REQUIRE(circle->getBoundingBoxWidth() == 20);
    REQUIRE(circle->getCurrentPositionX() == 10);
    REQUIRE(circle->getCurrentPositionY() == 10);

  }
//  SECTION( "Polygon" )
//  {
//    Polygon polygon5(5, 72);
//    Polygon polygon6(6, 72);
//  }
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
