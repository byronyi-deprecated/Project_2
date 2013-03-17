#ifndef LATTICE_H
#define LATTICE_H
#include <iostream>
#include <QColor>
#include <QImage>

class Lattice
{
public:
    Lattice(const Lattice&);
    Lattice(const size_t& width, const size_t& height);
    ~Lattice();

    void paintOnImage(QImage &);

    Lattice& operator=(const Lattice &);
    Lattice operator+(const Lattice &);
    bool operator==(const Lattice &);
    bool operator!=(const Lattice &);

    size_t getWidth() const {return width;}
    size_t getHeight() const {return height;}
    bool isSet(size_t nth_row, size_t nth_column) const
    {return lattice[nth_row * width + nth_column];}
    bool isHit(Lattice* const &a);    

    Lattice moveDown();
    Lattice moveLeft();
    Lattice moveRight();
    virtual Lattice rotate();
    void elimNthRow(size_t nth_row);
protected:
    void set(const size_t& nth_row, const size_t& nth_col);
    void reset(const size_t& nth_row, const size_t& nth_col);
    //coordinate of the shape center. Initiate in child class.
    size_t cRow;
    size_t cCol;
private:
    bool *lattice;
    size_t width;
    size_t height;
    QColor color;
};

#endif // LATTICE_H
