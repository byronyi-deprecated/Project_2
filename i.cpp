#include "i.h"

I::I(size_t width, size_t height) :
    Lattice(width, height)
{
    lattice->set(0, 3);
    lattice->set(0, 4);
    lattice->set(0, 5);
    lattice->set(0, 6);
}

Lattice I::rotate()
{

}
