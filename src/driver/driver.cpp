
#include <iostream>

#include "../linear_algebra/math_matrix/IMathMatrix.h"
#include "../linear_algebra/math_matrix/BaseMathMatrix.h"
#include "../linear_algebra/math_matrix/MathMatrix.h"
#include "../linear_algebra/math_matrix/TriDiagMathMatrix.h"

#include "../linear_algebra/QRDecompositor.h"

using namespace std;

int main () {

  IMathMatrix<double>* matrix = new MathMatrix<double>(3, 3);
  (*matrix)(0, 0) = -4;
  (*matrix)(0, 1) = 14;
  (*matrix)(0, 2) = 0;
  (*matrix)(1, 0) = -5;
  (*matrix)(1, 1) = 13;
  (*matrix)(1, 2) = 0;
  (*matrix)(2, 0) = -1;
  (*matrix)(2, 1) = 0;
  (*matrix)(2, 2) = 2;

  IMathMatrix<double>* triangle = new MathMatrix<double>(3, 3);
  IMathMatrix<double>* orthonormal = new MathMatrix<double>(3, 3);

  cout << "First Matrix = \n" << (*matrix) << endl;

  QRDecompositor<double> qrMethod;
  qrMethod(matrix, orthonormal, triangle, 5);

  cout << "First Matrix = \n" << (*matrix) << endl;
  cout << "Orthonormal Matrix = \n" << (*orthonormal) << endl;
  cout << "Triangle Matrix = \n" << (*triangle) << endl;


  return 0;
}
