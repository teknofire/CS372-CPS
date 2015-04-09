#include "Polygons.h"
#include <cmath>
#define PI 3.14159265358979323846

Polygons::Polygons(double numberOfSides, double sideLength):_numberOfSides(numberOfSides), _sideLength(sideLength)
{}
double Polygons::getBoundingBoxHeight()
{

    if(int(_numberOfSides)%2 != 0)
        return _sideLength*(1+cos(PI/_numberOfSides))/(2*sin(PI/_numberOfSides));
    else if(int(_numberOfSides)%4 == 0)
        return _sideLength*(cos(PI/_numberOfSides))/(sin(PI/_numberOfSides));
    else if(int(_numberOfSides)%2 == 0)
        return _sideLength*(cos(PI/_numberOfSides))/(sin(PI/_numberOfSides));
    return 0;
}

double Polygons::getBoundingBoxWidth()
{
    if(int(_numberOfSides)%2 != 0)
        return (_sideLength*sin((PI*(_numberOfSides-1))/(2*_numberOfSides)))/(sin(PI/_numberOfSides));
    else if(int(_numberOfSides)%4 == 0)
        return (_sideLength*cos(PI/_numberOfSides))/(sin(PI/_numberOfSides));
    else if(int(_numberOfSides)%2 == 0)
        return _sideLength/(sin(PI/_numberOfSides));
    return 0;
}

double Polygons::getCurrentPositionX()
{
    return 0;
}
double Polygons::getCurrentPositionY()
{
    return 0;
}
