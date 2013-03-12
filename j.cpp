#include "j.h"

J::J(size_t width, size height) : Lattice(width, height)
{
    lattice->set(0, 4);
    lattice->set(0, 5);
    lattice->set(0, 6);
    lattice->set(1, 6);
}

Lattice J::rotate()
{

}
