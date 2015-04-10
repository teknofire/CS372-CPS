#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <sstream>
using std::iostream;

class Circle : public Shape
{
    public:
        Circle(double radius);
        virtual double getBoundingBoxHeight() override;
        virtual double getBoundingBoxWidth() override;
        virtual double getCurrentPositionX() override;
        virtual double getCurrentPositionY() override;
        virtual const string buildPS() override;
        virtual void createPS(std::iostream & os) override;
    
    protected:
    private:
        double _radius;
};

#endif // CIRCLE_H
