#ifndef LATTICE_H
#define LATTICE_H
#include <iostream>

class Lattice
{
public:
    Lattice(const size_t& width, const size_t& height);
    ~Lattice();

    void set(const size_t& nth_row, const size_t& nth_col);
    void reset(const size_t& nth_row, const size_t& nth_col);
    bool hit(Lattice* const &a);
    bool *matrix() const {return lattice;}
private:
    bool *lattice;
    size_t width;
    size_t height;
};

#endif // LATTICE_H
