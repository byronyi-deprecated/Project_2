#ifndef I_H
#define I_H
#include "shape.h"

class I : public Shape
{
public:
    I(size_t width, size_t height);
    bool moveDown(Lattice *baseLattice);
    bool moveLeft(Lattice *baseLattice);
    bool moveRight(Lattice *baseLattice);
    bool rotate(Lattice *baseLattice);
};

#endif // I_H
