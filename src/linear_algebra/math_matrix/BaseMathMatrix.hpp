/*
 * Connor Walsh
 * BaseMathMatrix.hpp : implementation for BaseMathMatrix
 */

#include "BaseMathMatrix.h"

template <class T, template <class> class Derived>
size_t BaseMathMatrix<T, Derived>::rows() const
{
  std::cout << " In BaseMathMatrix rows function" << std::endl;
  return static_cast<const Derived<T>&>(*this).getRows();
}

template <class T, template <class> class Derived>
size_t BaseMathMatrix<T, Derived>::cols() const
{
    return static_cast<const Derived<T>&>(*this).getCols();
}

template <class T, template <class> class Derived>
IMathMatrix<T>* BaseMathMatrix<T, Derived>::clone()
{
  return new Derived<T>(static_cast<const Derived<T>&>(*this));
}
