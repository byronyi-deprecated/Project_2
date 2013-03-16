#include "o.h"

O::O(size_t width, size_t height) : Lattice(width, height)
{
    set(0, 4);
    set(1, 4);
    set(0, 5);
    set(1, 5);
}

Lattice& O::rotate()
{

}
