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
#include "Page.h"
#include "Path.h"
#include "Square.h"
#include "Triangle.h"
#include "Rectangle.h"

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
        
        SECTION( "Draw the Circle" )
        {
         
            string contentString = "";
            contentString = "0 0 10 0 360 arc\nstroke\n";
            
            REQUIRE(circle->buildPS() == contentString);
        }
        
    }
    SECTION( "4 sided polygon" )
    {
        double numberOfSides = 4;
        double sideLength = 1;
        shared_ptr<Shape> square = make_shared<Polygons>(numberOfSides, sideLength);
    
        REQUIRE(AreSame(square->getBoundingBoxHeight(), 1.0));
        REQUIRE(AreSame(square->getBoundingBoxWidth(), 1.0));
        REQUIRE(AreSame(square->getCurrentPositionX(), 0.5));
        REQUIRE(AreSame(square->getCurrentPositionY(), 0.5));
        
        shared_ptr<Shape> doubleSquare = make_shared<Polygons>(numberOfSides, sideLength * 2);
        
        REQUIRE(AreSame(doubleSquare->getBoundingBoxHeight(), 2.0));
        REQUIRE(AreSame(doubleSquare->getBoundingBoxWidth(), 2.0));
        REQUIRE(AreSame(doubleSquare->getCurrentPositionX(), 1.0));
        REQUIRE(AreSame(doubleSquare->getCurrentPositionY(), 1.0));
        
        SECTION( "render square" )
        {
            REQUIRE(square->buildPS() == "-0.5 -0.5 moveto\n1 0 rlineto\n90 rotate\n1 0 rlineto\n90 rotate\n1 0 rlineto\nclosepath\nstroke\n");
        }
        
    }
    
    SECTION( "Square" )
    {
        shared_ptr<Shape> square = make_shared<Square>(1);
        
        REQUIRE(AreSame(square->getBoundingBoxHeight(), 1.0));
        REQUIRE(AreSame(square->getBoundingBoxWidth(), 1.0));
        REQUIRE(AreSame(square->getCurrentPositionX(), 0.5));
        REQUIRE(AreSame(square->getCurrentPositionY(), 0.5));
    }
    
    SECTION( "Triangle" )
    {
        double sideLength = 1;
        
        shared_ptr<Shape> triangle = make_shared<Triangle>(sideLength);
        
        REQUIRE(AreSame(triangle->getBoundingBoxHeight(), .866025));
        REQUIRE(triangle->getBoundingBoxWidth() == 1.0);
        REQUIRE(triangle->getCurrentPositionX() == .5);
        REQUIRE(AreSame(triangle->getCurrentPositionY(), .866025 / 2));
        
    }
    
    SECTION( "5 Sided Polygon" )
    {
        double numberOfSides = 5;
        double sideLength = 1;
        shared_ptr<Shape> pentagon = make_shared<Polygons>(numberOfSides, sideLength);
        
        REQUIRE(AreSame(pentagon->getBoundingBoxHeight(), 1.53884));
        REQUIRE(AreSame(pentagon->getBoundingBoxWidth(), 1.61803));
        REQUIRE(AreSame(pentagon->getCurrentPositionX(), 1.61803/2.0));
        REQUIRE(AreSame(pentagon->getCurrentPositionY(), 1.53884/2.0));
    }
    
    SECTION( "6 Sided Polygon")
    {
        
        double numberOfSides = 6;
        double sideLength = 1;
        
        shared_ptr<Shape> hexagon = make_shared<Polygons>(numberOfSides, sideLength);
        
        REQUIRE(AreSame(hexagon->getBoundingBoxHeight(), 1.73205));
        REQUIRE(AreSame(hexagon->getBoundingBoxWidth(), 2.0));
        REQUIRE(AreSame(hexagon->getCurrentPositionX(), 1.0));
        REQUIRE(AreSame(hexagon->getCurrentPositionY(), 1.73205/2.0));
        
    }
    
    SECTION( "Rectangle")
    {
        
        shared_ptr<Shape> rectangle = make_shared<Rectangle>(1, 2);
        
        REQUIRE(AreSame(rectangle->getBoundingBoxHeight(), 2));
        REQUIRE(AreSame(rectangle->getBoundingBoxWidth(), 1));
        REQUIRE(AreSame(rectangle->getCurrentPositionX(), 0.5));
        REQUIRE(AreSame(rectangle->getCurrentPositionY(), 1));
    }
//    SECTION("Spacer")
//    {
//        
//    }

}

TEST_CASE( "Postscript", "[postcript]")
{
    SECTION( "Page object" )
    {
        Page page;
        
        REQUIRE(page.buildPS() == "showpage\n");
    }
    SECTION( "Path object" )
    {
        Path path;
        
        REQUIRE(path.buildPS() == "gsave\nnewpath\ngrestore\n");
    }
    
    SECTION( "Path with shape" )
    {
        double radius = 10;
        shared_ptr<Shape> circle = make_shared<Circle>(radius);
        shared_ptr<Path> path = make_shared<Path>(circle);
        
        REQUIRE(path->buildPS() == "gsave\nnewpath\n" + circle->buildPS() + "grestore\n");
        
        SECTION( "Page with a path" )
        {
            Page page(path);
            
            REQUIRE(page.buildPS() == path->buildPS() + "showpage\n");
        }
    }
    
    SECTION( "Page with path" )
    {
        shared_ptr<Path> path = make_shared<Path>();
        
        Page page(path);
        
        REQUIRE(page.buildPS() == "gsave\nnewpath\ngrestore\nshowpage\n");
    }
    
    SECTION("Rectangle Postscript")
    {
        shared_ptr<Shape> rectangle = make_shared<Rectangle>(1, 2);
        string testString = "-0.5 -1 moveto\n1 0 rlineto\n0 2 rlineto\n-1 0 rlineto\nclosepath\nstroke\n";
        REQUIRE(rectangle->buildPS() == testString);
    }
}
