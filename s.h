#ifndef S_H
#define S_H
#include "lattice.h"

class S : public Lattice
{
public:
    S(size_t width, size_t height);
    Lattice& rotate();
};

#endif // S_H
