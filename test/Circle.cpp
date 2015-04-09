#include "Circle.h"

Circle::Circle(double radius):_radius(radius)
{}
double Circle::getBoundingBoxHeight()
{
    return (2*_radius);
}
double Circle::getBoundingBoxWidth()
{
    return (2*_radius);
}
double Circle::getCurrentPositionX()
{
    return _radius;
}
double Circle::getCurrentPositionY()
{
    return _radius;
}
