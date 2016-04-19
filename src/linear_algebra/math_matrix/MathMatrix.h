/*
 * Connor Walsh
 * MathMatrix.h : Standard Math Matrix following the IMathMatrix interface
 */

#ifndef MATH_MATRIX_H
#define MATH_MATRIX_H

#pragma once

#include <stddef.h>
#include <iostream>

#include "BaseMathMatrix.h"

template <class T>
class MathMatrix : public BaseMathMatrix<T, MathMatrix>
{
  public:
    size_t getRows() const;
    size_t getCols() const;
};

#include "MathMatrix.hpp"

#endif
