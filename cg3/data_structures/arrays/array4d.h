/*
 * This file is part of cg3lib: https://github.com/cg3hci/cg3lib
 * This Source Code Form is subject to the terms of the GNU GPL 3.0
 *
 * @author Alessandro Muntoni (muntoni.alessandro@gmail.com)
 */

#ifndef CG3_ARRAY4D_H
#define CG3_ARRAY4D_H

#include <vector>
#include <assert.h>
#include <iomanip>
#include "array.h"
#include "array_bool.h"

namespace cg3 {

/**
 * @brief The Array4D class
 * Specialization of cg3::Array class with 4 dimensions.
 */
template <typename T>
class Array4D : public Array<T, 4>
{
public:
    Array4D();
    Array4D(
            unsigned long int sizeX,
            unsigned long int sizeY,
            unsigned long int sizeZ,
            unsigned long int sizeW);
    Array4D(
            unsigned long int sizeX,
            unsigned long int sizeY,
            unsigned long int sizeZ,
            unsigned long int sizeW,
            const T& value);
    Array4D(cg3::NestedInitializerLists<T, 4> values);
    unsigned long int sizeX() const;
    unsigned long int sizeY() const;
    unsigned long int sizeZ() const;
    unsigned long int sizeW() const;

    #ifdef CG3_OLD_NAMES_COMPATIBILITY
    inline unsigned long int getSizeX() const {return sizeX();}
    inline unsigned long int getSizeY() const {return sizeY();}
    inline unsigned long int getSizeZ() const {return sizeZ();}
    inline unsigned long int getSizeW() const {return sizeW();}
    #endif
};

} //namespace cg3

#include "array4d.tpp"

#endif // CG3_ARRAY4D_H
