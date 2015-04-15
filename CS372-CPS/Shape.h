#ifndef SHAPE_H
#define SHAPE_H

#include <sstream>
#include <string>
using std::string;
#include "Postscript.h"

class Shape : public Postscript
{
    public:
        virtual ~Shape() = default;
        virtual double getBoundingBoxHeight() = 0;
        virtual double getBoundingBoxWidth() = 0;
        virtual double getCurrentPositionX() = 0;
        virtual double getCurrentPositionY() = 0;
    private:
};

#endif // SHAPE_H
