#ifndef SHAPE_H
#define SHAPE_H

#include <sstream>

class Shape
{
    public:
        virtual ~Shape() = default;
        virtual double getBoundingBoxHeight() = 0;
        virtual double getBoundingBoxWidth() = 0;
        virtual double getCurrentPositionX() = 0;
        virtual double getCurrentPositionY() = 0;
        virtual void buildPS(std::stringstream &) = 0;
        virtual void createPS(const std::iostream &) = 0;
    private:
};

#endif // SHAPE_H
