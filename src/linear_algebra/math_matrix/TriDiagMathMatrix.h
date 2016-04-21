/*
 * Connor Walsh
 * TriDiagMathMatrix.h : Tridiagonal Math Matrix following the IMathMatrix interface
 */

#ifndef TRI_DIAG_MATH_MATRIX_H
#define TRI_DIAG_MATH_MATRIX_H

#pragma once

#include <stddef.h>
#include <iostream>

#include "BaseMathMatrix.h"
#include "IMathMatrix.h"

template <class T>
class TriDiagMathMatrix : public BaseMathMatrix<T, TriDiagMathMatrix>
{
  public:
    template <template <class> class MatrixType>
    TriDiagMathMatrix<T>& opAssign(const BaseMathMatrix<T, MatrixType>& rhs);

    bool opEquality(const IMathMatrix<T>& rhs) const;

    size_t getRows() const;
    size_t getCols() const;

  private:
    int myRows;
    int myColumns;
};

#include "TriDiagMathMatrix.hpp"

#endif
