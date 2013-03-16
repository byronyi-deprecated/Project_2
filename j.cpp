#include "j.h"

J::J(size_t width, size_t height) : Lattice(width, height)
{
    set(0, 4);
    set(0, 5);
    set(0, 6);
    set(1, 6);
}

Lattice& J::rotate()
{

}
