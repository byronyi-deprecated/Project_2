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
        lattice[nth_row * width + nth_col] = true;
    else
        std::cerr << "Given entry is out of range" << std::endl;
}

void Lattice::reset(const size_t& nth_row, const size_t& nth_col)
{
    if(nth_row < height && nth_col < height)
        lattice[nth_row * width + nth_col] = false;
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

Lattice Lattice::moveDown()
{
    for(size_t i = 0; i != width; ++i)
        if(lattice[ (height - 1) * width + i ])
            return *this;

    Lattice temp(*this);
    for(size_t i = height - 1; i != 0; --i)
        for(size_t j = 0; j != width; ++j)
            temp.lattice[i * width + j] = temp.lattice[(i-1) * width + j];

    for(size_t i = 0; i < width; ++i)
        temp.lattice[i] = false;

    return temp;
}

Lattice Lattice::moveLeft()
{
    for(size_t i = 0; i != height; ++i)
        if(lattice[i * width])
            return *this;

    Lattice temp(*this);
    for(size_t i = 0; i != width - 1; ++i)
        for(size_t j = 0; j != height; ++j)
            temp.lattice[j * width + i] = temp.lattice[j * width + (i + 1)];

    for(size_t i = 1; i != height; ++i)
        temp.lattice[i * width - 1] = false;

    return temp;
}

Lattice Lattice::moveRight()
{
    for(size_t i = 1; i != height; ++i)
        if(lattice[i * width - 1])
            return *this;

    Lattice temp(*this);
    for(size_t i = width - 1; i != 0; --i)
        for(size_t j = 0; j != height; ++j)
            temp.lattice[j * width + i] = temp.lattice[j * width + i - 1];

    for(size_t i = 0; i != height; ++i)
        temp.lattice[i * width + 1] = false;

    return temp;
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
