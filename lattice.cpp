#include "lattice.h"

Lattice::Lattice(const size_t& w, const size_t& h)
{
    width = w; height = h;
    lattice = new bool[width * height];
    for(size_t i = 0; i != width * height; ++i)
        lattice[i] = false;
}

Lattice::~Lattice()
{
    delete [] lattice;
}

void Lattice::set(const size_t& nth_row, const size_t& nth_col)
{
    if(nth_row < height && nth_col < width)
        lattice[nth_row * nth_col] = true;
    else
        std::cerr << "Given entry is out of range" << std::endl;
}

void Lattice::reset(const size_t& nth_row, const size_t& nth_col)
{
    if(nth_row < height && nth_col < height)
        lattice[nth_row * nth_col] = false;
    else
        std::cerr << "Given entry is out of range" << std::endl;
}

bool Lattice::hit(Lattice* const &a)
{
    if(a->width != this->width || a->height != this->height)
    {
        std::cerr << "Lattices with different size cannot compare" << std::endl;
        return true;
    }

    for(size_t i = 0; i != width * height; ++i)
        if(a->lattice[i] * this->lattice[i])
            return true;
    return false;
}
