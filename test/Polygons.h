#ifndef POLYGONS_H
#define POLYGONS_H

#include "Shape.h"


class Polygons : public Shape
{
    public:
        Polygons(double numberOfSides, double sideLength);
        virtual double getBoundingBoxHeight() override;
        virtual double getBoundingBoxWidth() override;
        virtual double getCurrentPositionX() override;
        virtual double getCurrentPositionY() override;
        virtual const string buildPS() override;
        virtual void createPS(std::iostream & os) override;
    protected:
    private:
        double _numberOfSides;
        double _sideLength;
};

#endif // POLYGONS_H
