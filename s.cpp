#include "s.h"

S::S(size_t width, size_t height) : Lattice(width, height)
{
    set(1, 4);
    set(1, 5);
    set(0, 5);
    set(0, 6);
}

Lattice& S::rotate()
{

}
