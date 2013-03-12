#include "shape.h"

Shape::Shape(size_t width, size_t height)
{
    lattice = new Lattice(width, height);
}

Shape::~Shape()
{
    delete lattice;
}
