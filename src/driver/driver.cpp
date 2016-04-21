
#include <iostream>

#include "../linear_algebra/math_matrix/IMathMatrix.h"
#include "../linear_algebra/math_matrix/BaseMathMatrix.h"
#include "../linear_algebra/math_matrix/MathMatrix.h"
#include "../linear_algebra/math_matrix/TriDiagMathMatrix.h"

using namespace std;

int main () {
  cout << "Creating a MathMatrix object!" << endl;

  MathMatrix<double> matrix(2, 5);
  MathMatrix<double> matrix2(3, 7);
  matrix[0][0] = 7;
  matrix[0][3] = 4;
  matrix[1][2] = 3;
  matrix[1][4] = 10;

  
  IMathMatrix<double>& refMatrix = matrix;
  IMathMatrix<double>& refMatrix2 = matrix2;

  cout << "Value at 1, 2 : " << refMatrix(1, 2) << std::endl;
  cout << "Value at 1, 2 : " << refMatrix[1][2] << std::endl;
  refMatrix2(0, 4) = 6;
  refMatrix2(0, 1) = 9;
  refMatrix2(1, 6) = 11;
  refMatrix2(1, 3) = 1;
  refMatrix2(2, 2) = 8;

  IMathMatrix<double>* ptrMatrix = &matrix;
  IMathMatrix<double>* ptrMatrix2 = &matrix2;


  cout << "Printing out matrix from base reference!" << endl;
  cout << refMatrix << endl;
  cout << refMatrix2 << endl;

  cout << "Are the equal? " << (refMatrix == refMatrix2) << endl;
  cout << "Are the unequal? " << (refMatrix != refMatrix2) << endl;

  cout << "Swapping first and second rows through pointer to Interface" << endl;
  ptrMatrix->swap(0, 1);
  ptrMatrix2->swap(0, 1);
  cout << *ptrMatrix << endl;
  cout << *ptrMatrix2 << endl;

  cout << "Calling rows and cols from a base reference!" << endl;
  cout << "rows: " << refMatrix.rows() << endl;
  cout << "cols: " << refMatrix.cols() << endl;
  cout << "rows: " << refMatrix2.rows() << endl;
  cout << "cols: " << refMatrix2.cols() << endl;
  cout << endl;

//  refMatrix = refMatrix2;

  cout << "Calling rows and cols from a base pointer!" << endl;
  cout << "rows: " << ptrMatrix->rows() << endl;
  cout << "cols: " << ptrMatrix->cols() << endl;
  cout << "rows: " << ptrMatrix2->rows() << endl;
  cout << "cols: " << ptrMatrix2->cols() << endl;
  cout << endl;

  cout << "Calling rows and cols from the cloned object" << endl;
  IMathMatrix<double>* clonedMatrix = ptrMatrix->clone();
  clonedMatrix->rows();
  clonedMatrix->cols();
  cout << endl;

  cout << "Does the cloned object equal the original? " << 
    ((*clonedMatrix) == refMatrix) << endl;

  cout << "Multiplying by scaler 4" << endl;
  cout << refMatrix << endl;
  cout << (refMatrix *= 4) << endl;

  cout << "Adding cloned to original\n" << ((*clonedMatrix) += refMatrix) << endl;
  cout << "Subtracting cloned from original\n" << (refMatrix -= (*clonedMatrix)) << endl;
  return 0;
}
