#ifndef Z_H
#define Z_H
#include "lattice.h"

class Z : public Lattice
{
public:
    Z(size_t width, size_t height);
    Lattice rotate();
};

#endif // Z_H
