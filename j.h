#ifndef J_H
#define J_H
#include "lattice.h"

class J : public Lattice
{
public:
    J(size_t width, size_t height);
    Lattice& rotate();
};

#endif // J_H
