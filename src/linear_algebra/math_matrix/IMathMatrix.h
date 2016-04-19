/*
 * Connor Walsh
 * IMathMatrix.h : Interface for a Mathematical Matrix class
 */

#ifndef I_MATH_MATRIX_H
#define I_MATH_MATRIX_H

#pragma once

#include <stddef.h>

template <class T>
class IMathMatrix
{
  public:
    virtual ~IMathMatrix() {};

//    virtual IMathMatrix<T>& operator=(const IMathMatrix<T>& rhs) = 0;

//    virtual IMathMatrix<T>& operator+=(const IMathMatrix<T>& rhs) = 0;
//    virtual IMathMatrix<T>& operator-=(const IMathMatrix<T>& rhs) = 0;

//    virtual T& operator()(size_t row, size_t column) = 0;

    virtual size_t rows() const = 0;
    virtual size_t cols() const = 0;

    virtual IMathMatrix<T>* clone() = 0; 

//    virtual IMathMatrix<T>& operator-() = 0;
};

#endif
