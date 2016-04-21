
#include <iostream>

#include "../linear_algebra/math_matrix/IMathMatrix.h"
#include "../linear_algebra/math_matrix/BaseMathMatrix.h"
#include "../linear_algebra/math_matrix/MathMatrix.h"
#include "../linear_algebra/math_matrix/TriDiagMathMatrix.h"

using namespace std;

int main () {

  MathMatrix<double> matrix(2, 3);
  matrix(0, 0) = 2;
  matrix(0, 1) = 1;
  matrix(0, 2) = 1;
  matrix(1, 0) = 3;
  matrix(1, 1) = 1;
  matrix(1, 2) = 2;

  MathMatrix<double> matrix2(3, 2);
  matrix2(0, 0) = 1;
  matrix2(0, 1) = 2;
  matrix2(1, 0) = 1;
  matrix2(1, 1) = 0;
  matrix2(2, 0) = 3;
  matrix2(2, 1) = 0;

  MathMatrix<double> copy;

  IMathMatrix<double>& firstMatrix = matrix;
  IMathMatrix<double>& secondMatrix = matrix2;
  IMathMatrix<double>& copyMatrix = copy;

  cout << "First Matrix = \n" << firstMatrix << endl;
  cout << "Second Matrix = \n" << secondMatrix << endl;

  cout << "Multiply first * second  = \n";
  IMathMatrix<double>* result = firstMatrix * secondMatrix;
  cout << *result << endl;
  delete result;

  cout << "Multiply by a scaler 4.5 = \n";
  result = firstMatrix * 4.5;
  cout << *result << endl;
  delete result;

  cout << "Assign copy to first matrix; copy = \n";
  copyMatrix = firstMatrix;
  cout << copy << endl;

  return 0;
}
