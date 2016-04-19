/*
 * Connor Walsh
 * BaseMathMatrix.h : CRTP Base for MathMatrix interface
 */

#ifndef BASE_MATH_MATRIX_H
#define BASE_MATH_MATRIX_H

#pragma once

#include <stddef.h>
#include <iostream>

#include "IMathMatrix.h"

template <class T, template <class> class Derived>
class BaseMathMatrix : public IMathMatrix<T> {
  public:
    virtual size_t rows() const;
    virtual size_t cols() const;

    virtual IMathMatrix<T>* clone();
};

#include "BaseMathMatrix.hpp"

#endif
