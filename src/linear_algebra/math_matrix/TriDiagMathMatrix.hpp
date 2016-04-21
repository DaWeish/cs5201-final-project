/*
 * Connor Walsh
 * TriDiagMathMatrix.hpp : Implementation file for TriDiagMathMatrix class
 */

#include "TriDiagMathMatrix.h"

template <class T>
template <template <class> class MatrixType>
TriDiagMathMatrix<T>& TriDiagMathMatrix<T>::opAssign(const BaseMathMatrix<T, MatrixType>& rhs)
{
  std::cout << "  In TriDiagMathMatrix opAssign" << std::endl;
}

template <class T>
bool TriDiagMathMatrix<T>::opEquality(const IMathMatrix<T>& rhs) const
{
  std::cout << "  In TriDiagMathMatrix opEquality" << std::endl;
}

template <class T>
size_t TriDiagMathMatrix<T>::getRows() const
{
  std::cout << "  In TriDiagMathMatrix getRows" << std::endl;
}

template <class T>
size_t TriDiagMathMatrix<T>::getCols() const
{
  std::cout << "  In TriDiagMathMatrix getCols function" << std::endl;
}
