////////////////////////////////////////////////////////////////////////////////
// author Connor Walsh
// file   MathMatrix.h
// brief  Class to represent a mathematical matrix
////////////////////////////////////////////////////////////////////////////////

#ifndef MATH_MATRIX2D_H
#define MATH_MATRIX2D_H

#include <iostream>
#include <cstddef>

#include "MathVector.h"
#include "IMathMatrix.h"
#include "../containers/Array.h"

////////////////////////////////////////////////////////////////////////////////
// class MathMatrix2D
// brief This class represents an nxm matrix and provides operations to add,
//  subtract, and multiply matrices, along with multiplying by sclaers and 
//  vectors
////////////////////////////////////////////////////////////////////////////////
template <class T>
class MathMatrix2D : public IMathMatrix<T>
{
  private:
    Array<MathVector<T>*> myRows;
    int myColumns;
    constexpr static int DEFAULT_SIZE = 2;

  public:
    typedef T value_type;
    typedef value_type* pointer;
    typedef value_type* iterator;
    typedef const value_type* const_iterator;
    typedef std::size_t size_type;

    bool equal_to(const IMathMatrix<T>& rhs) const;

    ////////////////////////////////////////////////////////////////////////////
    // fn Default Constructor
    // brief Creates a size zero matrix
    ////////////////////////////////////////////////////////////////////////////
    MathMatrix2D();

    ////////////////////////////////////////////////////////////////////////////
    // fn Size Constructor
    // brief Creates a matrix of size rows by columns and initializes values
    //    to zero
    // pre rows and columns must be greater than zero
    // post creates matrix of size rows x columns
    ////////////////////////////////////////////////////////////////////////////
    MathMatrix2D(size_type rows, size_type columns);

    ////////////////////////////////////////////////////////////////////////////
    // fn Copy Constructor
    // brief Creates a matrix which is a copy of another Matrix
    // post This now contains a copy of other and *this == other is true
    ////////////////////////////////////////////////////////////////////////////
    MathMatrix2D(const MathMatrix2D& other);

    ////////////////////////////////////////////////////////////////////////////
    // fn Move Constructor
    // brief Move Constructs a Matrix from a temporary
    // post This now contains other's data and other is ready to be destroyed
    ////////////////////////////////////////////////////////////////////////////
    MathMatrix2D(MathMatrix2D&& other);

    ////////////////////////////////////////////////////////////////////////////
    // fn Destructor
    // brief Cleans up after the Matrix
    // post All dynamically allocated memory is freed
    ////////////////////////////////////////////////////////////////////////////
    ~MathMatrix2D();

    ////////////////////////////////////////////////////////////////////////////
    // fn operator= (Assignment)
    // brief Sets this matrix equal to a copy of another matrix
    // post This is now equal to other
    ////////////////////////////////////////////////////////////////////////////
    MathMatrix2D& operator=(MathMatrix2D other) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    // fn swap(MathMatrix&)
    // brief this function swaps two matrices
    // post this now contains other's data and other contain's this' data
    ////////////////////////////////////////////////////////////////////////////
    void swap(MathMatrix2D& other) noexcept;

    ////////////////////////////////////////////////////////////////////////////
    // fn swap(int, int)
    // brief This function swaps two rows of this matrix
    // pre row1 and row2 must be valid row indexs
    // post this[row1] is swapped with this[row2]
    ////////////////////////////////////////////////////////////////////////////
    void swap(int row1, int row2);

    void print(std::ostream& os) const;

    ////////////////////////////////////////////////////////////////////////////
    // fn size
    // brief Returns the number of elements in the Matrix ie rows x columns
    // post returns the value requested
    ////////////////////////////////////////////////////////////////////////////
    size_type size() const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    // fn rows
    // brief Returns the number of rows in the Matrix
    // post returns a size_type representing the number of rows
    ////////////////////////////////////////////////////////////////////////////
    size_type rows() const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    // fn columns
    // brief Returns the number of columns in the Matrix
    // post returns a size_type representing the number of rows
    ////////////////////////////////////////////////////////////////////////////
    size_type columns() const noexcept;

    ////////////////////////////////////////////////////////////////////////////
    // fn operator+=/-=
    // brief These operators add/sub another matrix to/from this one
    // pre other must be of the same dimensions as this otherwise a domain error
    //  exception is thrown
    // post returns this after being added/subtracted to/from other
    ////////////////////////////////////////////////////////////////////////////
    MathMatrix2D& operator+=(const MathMatrix2D<T>& other);
    MathMatrix2D& operator-=(const MathMatrix2D<T>& other);

    ////////////////////////////////////////////////////////////////////////////
    // fn operator[] (const)
    // brief returns the horizontal MathVector requested
    // pre index must be a valid row index otherwise exception is thrown
    // post returns (const) reference to requested horizontal vector
    ////////////////////////////////////////////////////////////////////////////
    MathVector<T>& operator[](size_type index);
    const MathVector<T>& operator[](size_type index) const;

    ////////////////////////////////////////////////////////////////////////////
    // fn transpose
    // brief returns the transpose of this matrix
    // post returns a new matrix object representing this matrix's transpose
    ////////////////////////////////////////////////////////////////////////////
    MathMatrix2D transpose() const;
};

////////////////////////////////////////////////////////////////////////////////
// fn operator==/!=
// brief These functions test for (in)equality of two Matrices
// post returns true if the matrices represent the same values, false otherwise
////////////////////////////////////////////////////////////////////////////////
template <class T>
bool operator==(const MathMatrix2D<T>& lhs, const MathMatrix2D<T>& rhs);
template <class T>
bool operator!=(const MathMatrix2D<T>& lhs, const MathMatrix2D<T>& rhs);

////////////////////////////////////////////////////////////////////////////////
// fn operator+/-
// brief Operators for performing Matrix addition and subraction
// pre lhs and rhs must have the same dimensions otherwise exception is thrown
//    T must have the operator += defined
// post returns a matrix representing the result of lhs +/- rhs
////////////////////////////////////////////////////////////////////////////////
template <class T>
MathMatrix2D<T> operator+(MathMatrix2D<T> lhs, const MathMatrix2D<T>& rhs);
template <class T>
MathMatrix2D<T> operator-(MathMatrix2D<T> lhs, const MathMatrix2D<T>& rhs);

////////////////////////////////////////////////////////////////////////////////
// fn operator*(Matrix)
// brief This operator will perform matrix multiplication
// pre lhs.columns must be equal to rhs.rows else exception is thrown
// post returns the result of lhs * rhs
////////////////////////////////////////////////////////////////////////////////
template <class T>
MathMatrix2D<T> operator*(const MathMatrix2D<T>& lhs, const MathMatrix2D<T>& rhs);

////////////////////////////////////////////////////////////////////////////////
// fn operator*(scaler)
// brief Multiplies a Matrix by a scaler value
// post returns the result of scaler * matrix
////////////////////////////////////////////////////////////////////////////////
template <class T>
MathMatrix2D<T> operator*(MathMatrix2D<T> lhs, T scaler);
template <class T>
MathMatrix2D<T> operator*(T scaler, MathMatrix2D<T> rhs);

////////////////////////////////////////////////////////////////////////////////
// fn operator* (MathVector)
// brief Multiplies a Matrix by a vector
// pre rhs must be of size equal to lhs.columns else exception is thrown
// post returns the result of lhs * rhs
////////////////////////////////////////////////////////////////////////////////
template <class T>
MathVector<T> operator*(const MathMatrix2D<T>& lhs, const MathVector<T>& rhs);

////////////////////////////////////////////////////////////////////////////////
// fn operator<<
// brief Places a Matrix object on the ostream
// post os contains the textual representation of matrix
////////////////////////////////////////////////////////////////////////////////
template <class T>
std::ostream& operator<<(std::ostream& os, const MathMatrix2D<T>& matrix);

////////////////////////////////////////////////////////////////////////////////
// fn operator>>
// brief Attempts to parse a matrix object from an istream
// pre is must contain a representation of matrix otherwise exception is thrown
// post matrix now contains the values from is
////////////////////////////////////////////////////////////////////////////////
template <class T>
std::istream& operator>>(std::istream& is, MathMatrix2D<T>& matrix);

#include "MathMatrix2D.hpp"

#endif
