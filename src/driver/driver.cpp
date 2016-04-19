
#include <iostream>

#include "../linear_algebra/math_matrix/IMathMatrix.h"
#include "../linear_algebra/math_matrix/BaseMathMatrix.h"
#include "../linear_algebra/math_matrix/MathMatrix.h"

using namespace std;

int main () {
  cout << "Creating a MathMatrix object!" << endl;

  MathMatrix<double> matrix;
  IMathMatrix<double>& refMatrix = matrix;
  IMathMatrix<double>* ptrMatrix = &matrix;
  IMathMatrix<double>* clonedMatrix = ptrMatrix->clone();

  cout << "Calling rows and cols from a base reference!" << endl;
  cout << "Rows : " << refMatrix.rows() << endl;
  cout << "Cols : " << refMatrix.cols() << endl;

  cout << "Calling rows and cols from a base pointer!" << endl;
  cout << "Rows : " << ptrMatrix->rows() << endl;
  cout << "Cols : " << ptrMatrix->cols() << endl;

  cout << "Calling rows and cols from the matrix object" << endl;
  cout << "Rows : " << matrix.rows() << endl;
  cout << "Cols : " << matrix.cols() << endl;

  cout << "Calling rows and cols from the cloned object" << endl;
  cout << "Rows : " << clonedMatrix->rows() << endl;
  cout << "Cols : " << clonedMatrix->cols() << endl;

  cout << "Ending main" << endl;
  return 0;
}
