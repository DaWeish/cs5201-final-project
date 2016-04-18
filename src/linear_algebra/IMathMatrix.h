////////////////////////////////////////////////////////////////////////////////
// author Connor Walsh
// file   IMathMatrix.h
// brief  Interface of a mathematical matrix
////////////////////////////////////////////////////////////////////////////////

#ifndef IMATH_MATRIX_H
#define IMATH_MATRIX_H

#include <cstddef>
#include <iostream>

#include "../operators/equality.h"
#include "MathVector.h"

template <class T>
class IMathMatrix : private IEquality<IMathMatrix<T>>
{
  public:
    typedef T value_type;
    typedef value_type* pointer;
    typedef value_type* iterator;
    typedef const value_type* const_iterator;
    typedef std::size_t size_type;

    virtual ~IMathMatrix() {}

    virtual size_type rows() const noexcept = 0;
    virtual size_type columns() const noexcept = 0;

    // Used by IEquality to implement ==/!=
    virtual bool equal_to(const IMathMatrix& rhs) const = 0;

    virtual void print(std::ostream& os) const = 0;

    // This doesnt work since it returns an abstract type
//    virtual IMathMatrix& operator+=(const IMathMatrix& other) = 0;
//    virtual IMathMatrix& operator-=(const IMathMatrix& other) = 0;

//    virtual IMathMatrix& operator*=(const IMathMatrix& other) = 0;
//    virtual IMathMatrix& operator*=(const T& scaler) = 0;

    virtual MathVector<T>& operator[](size_type index) = 0;
    virtual const MathVector<T>& operator[](size_type index) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const IMathMatrix& matrix)
    {
      matrix.print(os);
      return os;
    }
};

#endif
