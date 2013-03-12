#include "lattice.h"

Lattice::Lattice(const Lattice &l)
{
    width = l.width;
    height = l.height;
    lattice = new bool[width * height];
    for(size_t i = 0; i != width * height; ++i)
        lattice[i] = l.lattice[i];
}

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

Lattice& Lattice::operator=(const Lattice &l)
{
    width = l.width;
    height = l.height;
    delete [] lattice;
    lattice = new bool[width * height];
    for(size_t i = 0; i != width * height; ++i)
        lattice[i] = l.lattice[i];
    return *this;
}

Lattice Lattice::operator+(const Lattice &l)
{
    if(width != l.width || height != width)
    {
        std::cerr << "Two matrix with different shape cannot add up" << std::endl;
        return *this;
    }
    for(size_t i = 0; i != width * height; ++i)
        lattice[i] = lattice[i] || l.lattice[i];
    return *this;
}

void Lattice::set(const size_t& nth_row, const size_t& nth_col)
{
    if(nth_row < height && nth_col < width)
        lattice[nth_row * widht + nth_col] = true;
    else
        std::cerr << "Given entry is out of range" << std::endl;
}

void Lattice::reset(const size_t& nth_row, const size_t& nth_col)
{
    if(nth_row < height && nth_col < height)
        lattice[nth_row * widht + nth_col] = false;
    else
        std::cerr << "Given entry is out of range" << std::endl;
}

bool Lattice::hit(Lattice* const &a)
{
    if(a->width != this->width || a->height != this->height)
    {
        std::cerr << "Lattices with different size cannot hit" << std::endl;
        return true;
    }

    for(size_t i = 0; i != width * height; ++i)
        if(a->lattice[i] * this->lattice[i])
            return true;
    return false;
}


void Lattice::elimNthRow(size_t nth_row)
{
    if(nth_row < height)
    {
        for(size_t i = nth_row; i != 0; --i)
            for(size_t j = 0; j != width; ++j)
                lattice[i * width + j] = lattice[(i - 1) * width + j];
        for(size_t i = 0; i != width; ++i)
            lattice[i] = false;
    }
    else
        std::cerr << "Given row is out of range" << std::endl;
    return;
}
