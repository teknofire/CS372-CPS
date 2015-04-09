#include "Circle.h"

Circle::Circle(double radius):_radius(radius)
{}
double Circle::getBoundingBoxHeight()
{
    return _radius;
}
double Circle::getBoundingBoxWidth()
{
    return _radius;
}
double Circle::getCurrentPositionX()
{
    return _radius;
}
double Circle::getCurrentPositionY()
{
    return _radius;
}
