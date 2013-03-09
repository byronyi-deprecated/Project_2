#include "shape.h"

Shape::Shape()
{
    lattice = new Lattice(10, 20);
}

Shape::~Shape()
{
    delete lattice;
}
