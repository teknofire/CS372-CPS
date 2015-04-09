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
        virtual void buildPS(std::stringstream &) override;
        virtual void createPS(const std::iostream & os) override;
    protected:
    private:
        double _numberOfSides;
        double _sideLength;
};

#endif // POLYGONS_H
