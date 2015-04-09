#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"


class Circle : public Shape
{
    public:
        Circle(double radius);
        virtual double getBoundingBoxHeight() override;
        virtual double getBoundingBoxWidth() override;
        virtual double getCurrentPositionX() override;
        virtual double getCurrentPositionY() override;
    protected:
    private:
        double _radius;
};

#endif // CIRCLE_H
