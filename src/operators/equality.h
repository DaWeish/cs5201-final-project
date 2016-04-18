////////////////////////////////////////////////////////////////////////////////
// author Connor Walsh
// file   equality.h
// brief  Interface to achieve equality operations for template base class
////////////////////////////////////////////////////////////////////////////////

#ifndef EQUALITY_H
#define EQUALITY_H

template <class T>
class IEquality
{
  friend bool operator==(const T& lhs, const T& rhs) { return lhs.equal_to(rhs); }
  friend bool operator!=(const T& lhs, const T& rhs) { return !lhs.equal_to(rhs); }
};

#endif
