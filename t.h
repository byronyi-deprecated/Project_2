#ifndef T_H
#define T_H
#include "lattice.h"

class T : public Lattice
{
public:
    T(size_t width, size_t height);
    Lattice rotate();
};

#endif // T_H
