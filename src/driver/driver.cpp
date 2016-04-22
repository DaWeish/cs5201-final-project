
#include <iostream>

#include "../linear_algebra/math_matrix/IMathMatrix.h"
#include "../linear_algebra/math_matrix/BaseMathMatrix.h"
#include "../linear_algebra/math_matrix/MathMatrix.h"
#include "../linear_algebra/math_matrix/TriDiagMathMatrix.h"
#include "../linear_algebra/math_matrix/DiagonalMathMatrix.h"
#include "../linear_algebra/math_matrix/UpTriangleMathMatrix.h"
#include "../linear_algebra/math_matrix/LowTriangleMathMatrix.h"

#include "../linear_algebra/QRDecompositor.h"

using namespace std;

int main () {

  IMathMatrix<double>* matrix = new MathMatrix<double>(3, 3);
  (*matrix)(0, 0) = 2;
  (*matrix)(0, 1) = 1;
  (*matrix)(0, 2) = 0;
  (*matrix)(1, 0) = 1;
  (*matrix)(1, 1) = 3;
  (*matrix)(1, 2) = 1;
  (*matrix)(2, 0) = 0;
  (*matrix)(2, 1) = 1;
  (*matrix)(2, 2) = 4;

  IMathMatrix<double>* triangle = new MathMatrix<double>(3, 3);
  IMathMatrix<double>* orthonormal = new MathMatrix<double>(3, 3);

  cout << "First Matrix = \n" << (*matrix) << endl;

  QRDecompositor<double> qrMethod;
  qrMethod(matrix, orthonormal, triangle, 30);

  cout << "First Matrix = \n" << (*matrix) << endl;
  cout << "Orthonormal Matrix = \n" << (*orthonormal) << endl;
  cout << "Triangle Matrix = \n" << (*triangle) << endl;

  IMathMatrix<double>* diagonal = new DiagonalMathMatrix<double>(3, 3);
  (*diagonal) = (*matrix);
  cout << "Diagonal matrix = \n" << (*diagonal) << endl;

  IMathMatrix<double>* upTriangle = new UpTriangleMathMatrix<double>(3, 3);
  (*upTriangle) = (*matrix);
  cout << "Up Triangle matrix = \n" << (*upTriangle) << endl;

  IMathMatrix<double>* lowTriangle = new LowTriangleMathMatrix<double>(3, 3);
  (*lowTriangle) = (*matrix);
  cout << "Low Triangle maktrix = \n" << (*lowTriangle) << endl;

  return 0;
}
