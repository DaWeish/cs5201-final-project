////////////////////////////////////////////////////////////////////////////////
// author Connor Walsh
// file   QRCompositor.h
// brief  Simple Functor to implement the QR Decomposition algorithm 
////////////////////////////////////////////////////////////////////////////////

#ifndef QRDECOMPOSITION_H
#define QRDECOMPOSITION_H

#include <vector>
#include <stdexcept>

#include "../linear_algebra/MathVector.h"

////////////////////////////////////////////////////////////////////////////////
// class QRDecompositor
// brief this Functor runs the QR Decomposition algorithm on the passed in
//    linearly independent vectors and returns the set of orthonormal vectors
//    and their multipliers
////////////////////////////////////////////////////////////////////////////////
template <class T>
class QRDecompositor
{
////////////////////////////////////////////////////////////////////////////////
// fn operator()
// brief This operator runs the QR Decomposition algorithm
// pre input must contain a set of n vectors each with length n. orthonormal must
// contain a set of n vectors each with length n. triangle must contain a set of
// n vectors each with length n and initialized to zero.
// post orthonormal now contains the set of orthonormal vectors built from input.
// triangle contains a triangle matrix of the multiplier values. This is true as
// long as division by zero does not occur, otherwise an exception is thrown.
////////////////////////////////////////////////////////////////////////////////
  public:
    void operator()(const std::vector<MathVector<T>>& input, 
        std::vector<MathVector<T>>& orthonormal,
        std::vector<MathVector<T>>& triangle) const;
};

template <class T>
void QRDecompositor<T>::operator()(const std::vector<MathVector<T>>& input, 
    std::vector<MathVector<T>>& orthonormal,
    std::vector<MathVector<T>>& triangle) const
{
  int size = input.size();
  for (auto k = 0; k < size; ++k)
  {

    for (auto i = 0; i < k; ++i)
    {
      triangle[k][i] = input[k] * orthonormal[i];
    }

    // Calculate the Orthagonalized vector
    MathVector<T> offset(size);
    MathVector<T> orthagonalized(size);

    for (auto j = 0; j < k; ++j)
    {
      offset += triangle[k][j] * orthonormal[j];
    }
    orthagonalized = input[k] - offset;

    // Calculate the kth r value
    triangle[k][k] = orthagonalized.getMagnitude();
    if (triangle[k][k] == 0)
    {
      throw std::domain_error("QRDecomposition requires division by zero!");
    }

    orthonormal[k] = (1.0 / triangle[k][k]) * orthagonalized;
  }
}

#endif
