#ifndef SHAPE_H
#define SHAPE_H

#include <sstream>
#include <string>
using std::string;
#include <memory>

#include "Postscript.h"
#include "DrawShape.h"

class Shape : public Postscript
{
public:
    virtual ~Shape() = default;
    Shape(): _drawShape(std::make_shared<DrawShape>()) {}
    virtual double getBoundingBoxHeight() = 0;
    virtual double getBoundingBoxWidth() = 0;
    virtual double getCurrentPositionX() = 0;
    virtual double getCurrentPositionY() = 0;

    std::shared_ptr<DrawShape> getDrawShape();
    void setDrawShape(std::shared_ptr<DrawShape>);
private:
    std::shared_ptr<DrawShape> _drawShape;
};

#endif // SHAPE_H
