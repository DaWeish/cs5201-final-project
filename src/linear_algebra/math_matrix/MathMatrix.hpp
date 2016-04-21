/*
 * Connor Walsh
 * MathMatrix.hpp : Implementation file for MathMatrix class
 */

#include <stdexcept>

#include "MathMatrix.h"

template <class T>
MathMatrix<T>::MathMatrix(size_t rows, size_t cols) : myColumns(cols)
{
  myRows = Array<MathVector<T>*>(rows);
  for (auto& row : myRows)
  {
    row = new MathVector<T>(myColumns);
  }
}

template <class T>
MathMatrix<T>::MathMatrix(const MathMatrix<T>& other) : myColumns(other.myColumns)
{
  myRows = Array<MathVector<T>*>(other.getRows());
  for (auto i = 0, numRows = (int)other.getRows(); i < numRows; ++i)
  {
    myRows[i] = new MathVector<T>(*(other.myRows[i]));
  }
}

template <class T>
MathMatrix<T>::MathMatrix(MathMatrix<T>&& other) : myColumns(other.myColumns)
{
  myRows = other.myRows;
  for (auto& row : other.myRows)
  {
    row = nullptr;
  }
  other.myColumns = 0;
}

template <class T>
MathMatrix<T>::~MathMatrix<T>()
{
  for (auto rowPointer : myRows)
  {
    delete(rowPointer);
  }
}

template <class T>
MathMatrix<T>& MathMatrix<T>::operator=(MathMatrix<T> rhs)
{
  swap(rhs);
  return *this;
}

template <class T>
void MathMatrix<T>::swap(MathMatrix<T>& other)
{
  std::swap(myColumns, other.myColumns);
  myRows.swap(other.myRows);
  return;
}

template <class T>
template <template <class> class MatrixType>
MathMatrix<T>& MathMatrix<T>::opAssign(const BaseMathMatrix<T, MatrixType>& rhs)
{
  std::cout << "  In MathMatrix opAssign" << std::endl;
}

template <class T>
bool MathMatrix<T>::opEquality(const IMathMatrix<T>& rhs) const
{
  if (myColumns != rhs.cols()) return false;
  if (myRows.size() != rhs.rows()) return false;

  for (int i = 0, numRows = myRows.size(); i < numRows; ++i)
  {
    for (int j = 0; j < myColumns; ++j)
    {
      if (at(i, j) != rhs(i, j)) return false;
    }
  }
  return true;
}

template <class T>
MathMatrix<T>& MathMatrix<T>::opPlusEquals(const IMathMatrix<T>& rhs)
{
  if (myRows.size() == rhs.rows() && myColumns == rhs.cols())
  {
    for (auto i = 0, numRows = (int)getRows(); i < numRows; ++i)
    {
      for (auto j = 0; j < myColumns; ++j)
      {
        at(i, j) += rhs(i, j);
      }
    }
    return *this;
  }
  else
  {
    throw std::domain_error("Cannot add two matrices of differing dimensions!");
  }
}

template <class T>
MathMatrix<T>& MathMatrix<T>::opMinusEquals(const IMathMatrix<T>& rhs)
{
  if (myRows.size() == rhs.rows() && myColumns == rhs.cols())
  {
    for (auto i = 0, numRows = (int)getRows(); i < numRows; ++i)
    {
      for (auto j = 0; j < myColumns; ++j)
      {
        at(i, j) -= rhs(i, j);
      }
    }
    return *this;
  }
  else
  {
    throw std::domain_error("Cannot add two matrices of differing dimensions!");
  }
}

template <class T>
MathMatrix<T>& MathMatrix<T>::opTimesEquals(const T& scaler)
{
  for (auto& row : myRows)
  {
    (*row) *= scaler;
  }
  return *this;
}

template <class T>
MathVector<T>& MathMatrix<T>::at(size_t index)
{
  return *(myRows.at(index));
}

template <class T>
const MathVector<T>& MathMatrix<T>::at(size_t index) const
{
  return *(myRows.at(index));
}

template <class T>
T& MathMatrix<T>::at(size_t row, size_t column)
{
  return (*(myRows.at(row)))[column];
}

template <class T>
const T& MathMatrix<T>::at(size_t row, size_t column) const
{
  return (*(myRows.at(row)))[column];
}

template <class T>
size_t MathMatrix<T>::getRows() const
{
  return myRows.size();
}

template <class T>
size_t MathMatrix<T>::getCols() const
{
  return myColumns;
}

template <class T>
void MathMatrix<T>::swapRows(size_t row1, size_t row2)
{
  std::swap(myRows[row1], myRows[row2]);
}

template <class T>
void MathMatrix<T>::printToStream(std::ostream& os) const
{
  for (auto i = 0, numRows = (int)getRows(); i < numRows; ++i)
  {
    os << *(myRows[i]) << "\n";
  }
}
