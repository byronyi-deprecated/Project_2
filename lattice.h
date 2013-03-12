#ifndef LATTICE_H
#define LATTICE_H
#include <iostream>

class Lattice
{
public:
    Lattice(const Lattice&);
    Lattice(const size_t& width, const size_t& height);
    ~Lattice();

    Lattice& operator=(const Lattice &);
    Lattice operator+(const Lattice &);

    size_t getWidth() const {return width;}
    size_t getHeight() const {return height;}
    bool isSet(size_t nth_row, size_t nth_column) const
    {return lattice[nth_row * width + nth_column];}
    void set(const size_t& nth_row, const size_t& nth_col);
    void reset(const size_t& nth_row, const size_t& nth_col);

    bool hit(Lattice* const &a);
    Lattice moveDown();
    Lattice moveLeft();
    Lattice moveRight();
    void elimNthRow(size_t nth_row);
private:
    bool *lattice;
    size_t width;
    size_t height;
};

#endif // LATTICE_H
