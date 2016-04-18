////////////////////////////////////////////////////////////////////////////////
// author Connor Walsh
// file   IMathMatrix.hpp
// brief  Interface of a mathematical matrix; global functions implemented
////////////////////////////////////////////////////////////////////////////////

#include "IMathMatrix.h"

template <class T>
IMathMatrix<T> operator+(IMathMatrix<T> lhs, const IMathMatrix<T>& rhs)
{
  return lhs += rhs;
}

template <class T>
IMathMatrix<T> operator-(IMathMatrix<T> lhs, const IMathMatrix<T>& rhs)
{
  return lhs -= rhs;
}

template <class T>
IMathMatrix<T> operator*(const IMathMatrix<T>& lhs, const IMathMatrix<T>& rhs)
{
  return lhs *= rhs;
}

template <class T>
IMathMatrix<T> operator*(const IMathMatrix<T>& matrix, const T& scaler)
{
  return matrix *= scaler;
}

template <class T>
MathVector<T> operator*(const IMathMatrix<T>& lhs, const MathVector<T>& rhs)
{
  return lhs.multiply_vector(rhs);
}
