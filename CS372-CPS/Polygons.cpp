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
        
        return (_sideLength * sin((PI*(_numberOfSides - 1)) / (2*_numberOfSides))  )/ (sin(PI/_numberOfSides) );
    
    else if(int(_numberOfSides)%4 == 0)
        
        return (_sideLength * cos(PI/_numberOfSides)) / (sin(PI/_numberOfSides));
    
    else if(int(_numberOfSides)%2 == 0)
        
        return (_sideLength/(sin(PI/_numberOfSides)));
    
    return 0.0;
    
}

double Polygons::getCurrentPositionX()
{
    return getBoundingBoxWidth()/2;
}
double Polygons::getCurrentPositionY()
{
    return getBoundingBoxHeight()/2;
}

const string Polygons::buildPS() {
    std::stringstream buff;
    double angle = 360.0 / _numberOfSides;
    double offset = _sideLength / 2.0;
    
    buff << -offset << " " << -getCurrentPositionY() << " moveto\n";
    buff << _sideLength << " 0 rlineto\n";
    
    for(int ii=0; ii < (_numberOfSides-2); ++ii)
    {
        buff << angle << " rotate\n";
        buff << _sideLength << " 0 rlineto\n";
    }
    buff << "closepath\n";
    buff << Shape::getDrawShape()->buildPS();
    
    return buff.str();
    
}