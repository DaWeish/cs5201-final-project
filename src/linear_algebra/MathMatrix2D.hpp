////////////////////////////////////////////////////////////////////////////////
// author Connor Walsh
// file   MathMatrix.h
// brief  Implementation of a mathematical matrix
////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>
#include <string>
#include <sstream>
#include <iostream>

#include "MathMatrix2D.h"

template <class T>
MathMatrix2D<T>::MathMatrix2D() : myColumns(0) {}

template <class T>
MathMatrix2D<T>::MathMatrix2D(MathMatrix2D<T>::size_type rows,
    MathMatrix2D<T>::size_type columns) : myColumns(columns)
{
  myRows = Array<MathVector<T>*>(rows);
  for (auto& row : myRows)
  {
    row = new MathVector<T>(columns);
  }
}

template <class T>
MathMatrix2D<T>::MathMatrix2D(const MathMatrix2D<T>& other)
  : myColumns(other.myColumns)
{
  myRows = Array<MathVector<T>*>(other.rows());
  for (auto i = 0, numRows = (int)other.rows(); i < numRows; ++i)
  {
    myRows[i] = new MathVector<T>(*(other.myRows[i]));
  }
}

template <class T>
MathMatrix2D<T>::MathMatrix2D(MathMatrix2D<T>&& other) : myColumns(other.myColumns)
{
  myRows = other.myRows;
  for (auto& row : other.myRows)
  {
    row = nullptr;
  }

  other.myColumns = 0;
}

template <class T>
MathMatrix2D<T>::~MathMatrix2D()
{
  for (auto rowPointer : myRows)
  {
    delete(rowPointer);
  }
}

template <class T>
MathMatrix2D<T>& MathMatrix2D<T>::operator=(MathMatrix2D<T> other) noexcept
{
  swap(other);
  return *this;
}

template <class T>
void MathMatrix2D<T>::swap(MathMatrix2D<T>& other) noexcept
{
  std::swap(myColumns, other.myColumns);
  myRows.swap(other.myRows);

  return;
}

// Row 1 and row 2 must refer to rows in the matrix
template <class T>
void MathMatrix2D<T>::swap(int row1, int row2)
{
  std::swap(myRows[row1], myRows[row2]);
}

template <class T>
typename MathMatrix2D<T>::size_type MathMatrix2D<T>::size() const noexcept
{
  return rows() * columns();
}

template <class T>
typename MathMatrix2D<T>::size_type MathMatrix2D<T>::rows() const noexcept
{
  return myRows.size();
}

template <class T>
typename MathMatrix2D<T>::size_type MathMatrix2D<T>::columns() const noexcept
{
  return myColumns;
}

template <class T>
MathMatrix2D<T>& MathMatrix2D<T>::operator+=(const MathMatrix2D<T>& other)
{
  if (rows() == other.rows() && columns() == other.columns())
  {
    for (auto i = 0, numRows = (int)rows(); i < numRows; ++i)
    {
      *(myRows[i]) += *(other.myRows[i]);
    }
    return *this;
  }
  else
  {
    throw std::domain_error("Cannot add two matrices of differing dimensions!");
  }

}

template <class T>
MathMatrix2D<T>& MathMatrix2D<T>::operator-=(const MathMatrix2D<T>& other)
{
  if (rows() == other.rows() && columns() == other.columns())
  {
    for (auto i = 0, numRows = (int)rows(); i < numRows; ++i)
    {
      *(myRows[i]) -= *(other.myRows[i]);
    }
    return *this;
  }
  else
  {
    throw std::domain_error("Cannot subtract two matrices of differing dimensions!");
  }
}

template <class T>
MathVector<T>& MathMatrix2D<T>::operator[](MathMatrix2D<T>::size_type index)
{
  return *(myRows.at(index));
}

template <class T>
const MathVector<T>& MathMatrix2D<T>::operator[] (MathMatrix2D<T>::size_type index) const
{
  return *(myRows.at(index));
}

template <class T>
MathMatrix2D<T> MathMatrix2D<T>::transpose() const
{
  MathMatrix2D<T> result(columns(), rows());
  for (int row = 0, rowNum = rows(); row < rowNum; ++row)
  {
    for (int col = 0, colNum = columns(); col < colNum; ++col)
    {
      result[col][row] = (*this)[row][col];
    }
  }

  return result;
}

template <class T>
bool MathMatrix2D<T>::equal_to(const IMathMatrix<T>& rhs) const
{
  if (this == &rhs)
    return true;

  if (rows() == rhs.rows() && columns() == rhs.columns())
  {
    for (auto i = 0, size = (int)rows(); i < size; ++i)
    {
      if (!((*this)[i] == rhs[i]))
      {
        return false;
      }
    }
  }
  else
  {
    return false;
  }

  return true;

}

template <class T>
void MathMatrix2D<T>::print(std::ostream& os) const
{
  for (auto i = 0, numRows = (int)rows(); i < numRows; ++i)
  {
    os << (*this)[i] << "\n";
  }
}

template <class T>
bool operator==(const MathMatrix2D<T>& lhs, const MathMatrix2D<T>& rhs)
{
  if (&lhs == &rhs)
    return true;

  if (lhs.rows() == rhs.rows() && lhs.columns() == rhs.columns())
  {
    for (auto i = 0, size = (int)lhs.rows(); i < size; ++i)
    {
      if (!(lhs[i] == rhs[i]))
      {
        return false;
      }
    }
  }
  else
  {
    return false;
  }

  return true;
}

template <class T>
bool operator!=(const MathMatrix2D<T>& lhs, const MathMatrix2D<T>& rhs)
{
  return (!(lhs == rhs));
}

template <class T>
MathMatrix2D<T> operator+(MathMatrix2D<T> lhs, const MathMatrix2D<T>& rhs)
{
  return (lhs += rhs);
}

template <class T>
MathMatrix2D<T> operator-(MathMatrix2D<T> lhs, const MathMatrix2D<T>& rhs)
{
  return (lhs -= rhs);
}

template <class T>
MathMatrix2D<T> operator*(const MathMatrix2D<T>& lhs, const MathMatrix2D<T>& rhs)
{
  if (lhs.columns() != rhs.rows())
  {
    throw std::domain_error("Matrices must be of correct dimensions to multiply!");
  }

  MathMatrix2D<T> result(lhs.rows(), rhs.columns());
  MathMatrix2D<T> rhsTrans = rhs.transpose();
  for (int i = 0, iSize = (int)rhsTrans.rows(); i < iSize; ++i)
  {
    for (int j = 0, jSize = (int)lhs.rows(); j < jSize; ++j)
    {
      result[j][i] = rhsTrans[i].dotProduct(lhs[j]);
    }
  }

  return result;
}

template <class T>
MathMatrix2D<T> operator*(MathMatrix2D<T> lhs, T scaler)
{
  for (int row = 0, numRows = lhs.rows(); row < numRows; ++row)
  {
    lhs[row] *= scaler;
  }
  return lhs;
}

template <class T>
MathMatrix2D<T> operator*(T scaler, MathMatrix2D<T> rhs)
{
  return (rhs * scaler);
}

template <class T>
MathVector<T> operator*(const MathMatrix2D<T>& lhs, const MathVector<T>& rhs)
{
  if (lhs.columns() != rhs.size())
  {
    throw std::domain_error("Matrix and Vector must have compatible dimensions to multiply!");
  }

  MathVector<T> result(rhs.size());
  for (int row = 0, numRows = lhs.rows(); row < numRows; ++row)
  {
    MathVector<T> currentRow = lhs[row];
    result[row] = (currentRow.dotProduct(rhs));
  }
  return result;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const MathMatrix2D<T>& matrix)
{
  for (auto i = 0, numRows = (int)matrix.rows(); i < numRows; ++i)
  {
    os << matrix[i] << "\n";
  }
  return os;
}

template <class T>
std::istream& operator>>(std::istream& is, MathMatrix2D<T>& matrix)
{
  std::string line;
  for (int row = 0, numRows = matrix.rows(); row < numRows; ++row)
  {
    if (is.good())
    {
      getline(is, line);
      std::istringstream lineStream(line);

      lineStream >> matrix[row];
    }
    else
    {
      break;
    }
  }
  return is;
}
