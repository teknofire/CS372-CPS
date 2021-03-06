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
#include "Spacer.h"
#include "Rotate.h"
#include "Scaled.h"
#include "Layered.h"
#include "Vertical.h"
#include "Horizontal.h"
#include "DrawShape.h"

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

TEST_CASE( "Drawing Shapes with Color" )
{
	DrawShape ds;
	SECTION( "Default values" )
	{
		REQUIRE(ds.buildPS() == "0 0 0 setrgbcolor\nstroke\n");
	}
	
	SECTION( "RED values" )
	{
		ds.setColor(255, 0, 0);
		REQUIRE(ds.buildPS() == "1 0 0 setrgbcolor\nstroke\n");
	}
	
	SECTION( "Blue values" )
	{
		ds.setColor(0, 0, 255);
		REQUIRE(ds.buildPS() == "0 0 1 setrgbcolor\nstroke\n");
	}
	
	SECTION( "Green values" )
	{
		ds.setColor(0, 255, 0);
		REQUIRE(ds.buildPS() == "0 1 0 setrgbcolor\nstroke\n");
	}
	
	SECTION( "Fill type" )
	{
		ds.setDrawType("fill");
		REQUIRE(ds.buildPS() == "0 0 0 setrgbcolor\nfill\n");
	}
}

TEST_CASE( "Shapes", "[shape]")
{
	
    double radius = 10;
    shared_ptr<Shape> circle = make_shared<Circle>(radius);
    double numberOfSides = 4;
    double sideLength = 1;
    shared_ptr<Shape> square = make_shared<Polygons>(numberOfSides, sideLength);
    shared_ptr<Shape> triangle = make_shared<Triangle>(sideLength);
    
    shared_ptr<Path> circlePath = make_shared<Path>(circle);
    shared_ptr<Path> squarePath = make_shared<Path>(square);
    shared_ptr<Path> trianglePath = make_shared<Path>(triangle);
    
    SECTION( "Layered Shapes" ) {
        
        shared_ptr<Layered> layer = make_shared<Layered>(std::vector<shared_ptr<Shape>> {circle, square, triangle});
        
        REQUIRE(layer->buildPS() == "gsave\n" + circlePath->buildPS() + squarePath->buildPS() + trianglePath->buildPS() + "grestore\n");
        REQUIRE(layer->getBoundingBoxHeight() == 20);
        REQUIRE(layer->getBoundingBoxWidth() == 20);
        REQUIRE(layer->getCurrentPositionX() == 10);
        REQUIRE(layer->getCurrentPositionY() == 10);
        
        SECTION( "Vertical and Horizontal Shapes" ){
			
			std::stringstream buff;
			
			buff << circlePath->buildPS() << "0 20 translate\n";
			buff << squarePath->buildPS() << "0 1 translate\n";
			buff << trianglePath->buildPS() << "0 " << triangle->getBoundingBoxHeight() << " translate\n";
			
            shared_ptr<Vertical> vert = make_shared<Vertical>(std::vector<shared_ptr<Shape>> {circle, square, triangle});
            
            //REQUIRE(vert->buildPS() == buff.str());
            REQUIRE(AreSame(vert->getBoundingBoxHeight(), 21.866025));
            REQUIRE(vert->getBoundingBoxWidth() == 20);
            REQUIRE(vert->getCurrentPositionX() == 10);
            REQUIRE(AreSame(vert->getCurrentPositionY(), (21.866025 / 2)));
			
			std::stringstream buff2;
			
//			buff << circlePath->buildPS() << "0 20 translate\n";
//			buff << squarePath->buildPS() << "0 1 translate\n";
//			buff << trianglePath->buildPS() << "0 " << triangle->getBoundingBoxHeight() << " translate\n";
			
			shared_ptr<Horizontal> horizontal = make_shared<Horizontal>(std::vector<shared_ptr<Shape>> {circle, square, triangle});
			
			//REQUIRE(horizontal->buildPS() == buff.str());
			REQUIRE(AreSame(horizontal->getBoundingBoxWidth(), 22));
			REQUIRE(horizontal->getBoundingBoxHeight() == 20);
			REQUIRE(horizontal->getCurrentPositionY() == 10);
			REQUIRE(AreSame(horizontal->getCurrentPositionX(), (22 / 2)));
			
        }
    }
	
    SECTION( "Circle" )
    {
        
        REQUIRE(circle->getBoundingBoxHeight() == 20);
        REQUIRE(circle->getBoundingBoxWidth() == 20);
        REQUIRE(circle->getCurrentPositionX() == 10);
        REQUIRE(circle->getCurrentPositionY() == 10);
        
        SECTION( "Draw the Circle" )
        {
         
            string contentString = "";
            contentString = "0 0 10 0 360 arc\n0 0 0 setrgbcolor\nstroke\n";
            
            REQUIRE(circle->buildPS() == contentString);
        }
        
    }
    SECTION( "4 sided polygon" )
    {
        
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
            REQUIRE(square->buildPS() == "-0.5 -0.5 moveto\n1 0 rlineto\n90 rotate\n1 0 rlineto\n90 rotate\n1 0 rlineto\nclosepath\n0 0 0 setrgbcolor\nstroke\n");
        }
        
    }
    
    SECTION( "Square" )
    {
        shared_ptr<Shape> square = make_shared<Square>(1);
        
        REQUIRE(AreSame(square->getBoundingBoxHeight(), 1.0));
        REQUIRE(AreSame(square->getBoundingBoxWidth(), 1.0));
        REQUIRE(AreSame(square->getCurrentPositionX(), 0.5));
        REQUIRE(AreSame(square->getCurrentPositionY(), 0.5));
        
        SECTION( "Scaled Square" ){
            
            shared_ptr<Shape> scaledSquare = make_shared<Scaled>(square, 2.0, 2.0);
            
            REQUIRE(scaledSquare->buildPS() == "2 2 scale\n" + square->buildPS());
            REQUIRE(AreSame(scaledSquare->getBoundingBoxHeight(), 2.0));
            REQUIRE(AreSame(scaledSquare->getBoundingBoxWidth(), 2.0));
            REQUIRE(AreSame(scaledSquare->getCurrentPositionX(), 1.0));
            REQUIRE(AreSame(scaledSquare->getCurrentPositionY(), 1.0));
            
            shared_ptr<Shape> scaledSquare2 = make_shared<Scaled>(square, 10.0, 1.0);
            
            REQUIRE(scaledSquare2->buildPS() == "10 1 scale\n" + square->buildPS());
            REQUIRE(AreSame(scaledSquare2->getBoundingBoxHeight(), 1.0));
            REQUIRE(AreSame(scaledSquare2->getBoundingBoxWidth(), 10.0));
            REQUIRE(AreSame(scaledSquare2->getCurrentPositionX(), 5.0));
            REQUIRE(AreSame(scaledSquare2->getCurrentPositionY(), 0.5));
            
        }
    }
    
    SECTION( "Triangle" )
    {
        
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
        
        SECTION( "90 Rotated shape" )
        {
            shared_ptr<Shape> rotated = make_shared<Rotate>(pentagon, 90);
            
            REQUIRE(rotated->buildPS() == "gsave\n90 rotate\n" + pentagon->buildPS() + "grestore\n");
            REQUIRE(AreSame(rotated->getBoundingBoxHeight(), 1.61803));
            REQUIRE(AreSame(rotated->getBoundingBoxWidth(), 1.53884));
            REQUIRE(AreSame(rotated->getCurrentPositionX(), 1.53884/2.0));
            REQUIRE(AreSame(rotated->getCurrentPositionY(), 1.61803/2.0));
        }
        
        SECTION( "270 Rotated shape" )
        {
            shared_ptr<Shape> rotated3 = make_shared<Rotate>(pentagon, 270);
            
            REQUIRE(rotated3->buildPS() == "gsave\n270 rotate\n" + pentagon->buildPS() + "grestore\n");
            REQUIRE(AreSame(rotated3->getBoundingBoxHeight(), 1.61803));
            REQUIRE(AreSame(rotated3->getBoundingBoxWidth(), 1.53884));
            REQUIRE(AreSame(rotated3->getCurrentPositionX(), 1.53884/2.0));
            REQUIRE(AreSame(rotated3->getCurrentPositionY(), 1.61803/2.0));
        }
        
        SECTION( "180 Rotated shape" )
        {
            shared_ptr<Shape> rotated2 = make_shared<Rotate>(pentagon, 180);
            
            REQUIRE(rotated2->buildPS() == "gsave\n180 rotate\n" + pentagon->buildPS() + "grestore\n");
            REQUIRE(AreSame(rotated2->getBoundingBoxHeight(), 1.53884));
            REQUIRE(AreSame(rotated2->getBoundingBoxWidth(), 1.61803));
            REQUIRE(AreSame(rotated2->getCurrentPositionX(), 1.61803/2.0));
            REQUIRE(AreSame(rotated2->getCurrentPositionY(), 1.53884/2.0));
        }
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
    SECTION("Spacer")
    {
        shared_ptr<Shape> spacer = make_shared<Spacer>(1, 2);
        REQUIRE(AreSame(spacer->getBoundingBoxHeight(), 2));
        REQUIRE(AreSame(spacer->getBoundingBoxWidth(), 1));
        REQUIRE(AreSame(spacer->getCurrentPositionX(), 0.5));
        REQUIRE(AreSame(spacer->getCurrentPositionY(), 1));
    }
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
        string testString = "-0.5 -1 moveto\n1 0 rlineto\n0 2 rlineto\n-1 0 rlineto\nclosepath\n0 0 0 setrgbcolor\nstroke\n";
        REQUIRE(rectangle->buildPS() == testString);
    }
	
    SECTION("Spacer Postscript")
    {
        shared_ptr<Shape> spacer = make_shared<Spacer>(1, 2);
        string testString = "";
        REQUIRE(spacer->buildPS()== testString);

    }
}
