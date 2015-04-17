UAF CS 372
Project 2 - Postscript

Contributors:
Will Fisher
Jacob McKenna
Adam Walters
Dylan Tucker

Files we created:
  1. Circle.h Circle.cpp
	Generates circles given a radius r.
  2. CustomShape.h CustomShape.cpp
	This is the custom shape that creates orbits given the initial orbit radius and number of orbits.
  3. Horizontal.h Horizontal.cpp
	A horizontal stack of shapes given a vector of shapes.
  4. Layered.h Layered.cpp
	A layered set of shapes given a vector of shapes.
  5. NullPostscript.h NullPostscript.cpp
	Used for testing.
  6. Page.h Page.cpp
	/**/
  7. Path.h Path.cpp
	Acts as a wrapper for gsave and grestore.
  8. Polygons.h Polygons.cpp
	Creates a polygon given the number of sides and the side length.
  9. Postscript.h 
	Uses decorator pattern for building Postscript. 
 10. Rectangle.h Rectangle.cpp
	Generates a rectangle given the width and the height.
 11. Rotate.h Rotate.cpp
	Rotates a shape about its center point.
 12. Scaled.h Scaled.cpp
	Rescales a shape given the shape and factors in terms of x (width) and y (height).
 13. Shape.h Shape.cpp
	All shapes inherit from this class (and PostScript), which draws the shapes bounding box.
 14. Spacer.h 
	Creates a rectangle sized space.
 15. Square.h
	Generates a square (using the polygon constructor) with four sides and a given side length. 
 16. Triangle.h 
	Generates a triangle (using the polygon constructor) with three sides and a given side length.
 17. Vertical.h Vertical.cpp
	A vertical stack of shapes given a vector of shapes.
 18. DrawShape.h DrawShape.cpp
	Uses Strategy Pattern to mix in the functionality for different color planets and fill or stroke on all shapes. 

Aspects - 
All of our shapes use the Decorator pattern. 
Our CustomShape takes different parameters for different patterns. (ie, different number of orbits and planets) 
Added drawShape function,


All code is executed in the main.cpp file, where multiple pages with (test) shapes are drawn. This is including our custom shape of Orbits.
It also generates two separate files: output.ps and solar_system.ps. 
