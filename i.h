#ifndef I_H
#define I_H
#include "lattice.h"
#include <QColor>

class I : public Lattice
{
public:
    I(size_t width, size_t height);
    Lattice rotate();
private:
    QRgb color;
};

#endif // I_H
