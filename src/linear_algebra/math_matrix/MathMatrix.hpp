/*
 * Connor Walsh
 * MathMatrix.hpp : Implementation file for MathMatrix class
 */

#include "MathMatrix.h"

template <class T>
size_t MathMatrix<T>::getRows() const
{
  std::cout << "  In MathMatrix getRows function" << std::endl;
  return 5; 
}

template <class T>
size_t MathMatrix<T>::getCols() const
{
  std::cout << "  In MathMatrix getCols function" << std::endl;
  return 10;
}
