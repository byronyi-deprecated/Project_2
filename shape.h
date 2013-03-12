#ifndef SHAPE_H
#define SHAPE_H

#include "lattice.h"
class Shape
{
public:
    Shape(size_t width, size_t height);
    ~Shape();
    virtual bool moveLeft(Lattice* baseLattice) = 0;
    virtual bool moveRight(Lattice* baseLattice) = 0;
    virtual bool moveDown(Lattice* baseLattice) = 0;
    virtual bool rotate(Lattice* baseLattice) = 0;
protected:
    Lattice* lattice;
};

#endif // SHAPE_H
