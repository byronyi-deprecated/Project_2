#ifndef O_H
#define O_H
#include "lattice.h"

class O : public Lattice
{
public:
    O(size_t width, size_t height);
    Lattice rotate();
};

#endif // O_H
