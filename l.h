#ifndef L_H
#define L_H
#include "lattice.h"

class L : public Lattice
{
public:
    L(size_t width, size_t height);
    Lattice rotate();
};

#endif // L_H
