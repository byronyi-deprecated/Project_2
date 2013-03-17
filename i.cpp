#include "i.h"

I::I(size_t width, size_t height) :
    Lattice(width, height)
{
    set(0, 3);
    set(0, 4);
    set(0, 5);
    set(0, 6);

    cRow = 0;
    cCol = 4;
}

Lattice I::rotate()
{

}
