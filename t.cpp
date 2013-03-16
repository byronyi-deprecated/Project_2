#include "t.h"

T::T(size_t width, size_t height) : Lattice(width, height)
{
    set(0, 4);
    set(0, 5);
    set(1, 5);
    set(0, 6);
}

Lattice& T::rotate()
{

}
