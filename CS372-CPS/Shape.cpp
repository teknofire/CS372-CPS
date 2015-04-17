#include "Shape.h"


std::shared_ptr<DrawShape> Shape::getDrawShape()
{
    return _drawShape;
}
void Shape::setDrawShape(std::shared_ptr<DrawShape> drawShape)
{
    _drawShape = drawShape;
}