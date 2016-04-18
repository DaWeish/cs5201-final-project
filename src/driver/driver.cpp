////////////////////////////////////////////////////////////////////////////////
// author Connor Walsh
// file   driver.cpp
// brief  Driver class for Assignment 3
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

#include "../linear_algebra/MathVector.h"
#include "../linear_algebra/MathMatrix2D.h"
#include "../linear_algebra/GaussianEliminiation.h"
#include "../linear_algebra/IMathMatrix.h"

using namespace std;

int main(int argc, char** argv)
{  
  if (argc != 2)
  {
    cout << "Usage: " << argv[0] << " input_file " << endl;
    return 1;
  }

  ifstream inputFile;
  int numPoints = 0;
  GaussianElimination<double> gaussSolver;

  inputFile.open(argv[1]);
  if (inputFile.is_open())
  {
    inputFile >> numPoints;
    if (numPoints < 0)
    {
      cout << "Cannot work on a negative number of points!" << endl;
      return 1;
    }

    MathVector<double> xValues(numPoints);
    MathVector<double> yValues(numPoints);

    for (auto i = 0; i < numPoints && inputFile.good(); ++i)
    {
      inputFile >> xValues[i];

      if (inputFile.good())
      {
        inputFile >> yValues[i];
      }
      else
      {
        cout << "Failed to parse two points for row " << i << ". Quitting."
          << endl;
        return 1;
      }
    }

    cout << std::setprecision(5);
    cout << std::fixed;
    cout << std::showpoint;
    cout << std::right;

//    std::cout << "== X Values ==\n" << xValues << endl;
//    std::cout << "== Y Values ==\n" << yValues << endl;

    MathMatrix2D<double> vandermonde(numPoints, numPoints);
    for (int row = 0, numRows = numPoints; row < numRows; ++row)
    {
      for (int col = 0, numCols = numPoints; col < numCols; ++col)
      {
        vandermonde[row][col] = pow(xValues[row], col);
      }
    }

    cout << "== Testing Matrix Interface ==\n";
    IMathMatrix<double>& baseReference = vandermonde;
    cout << "== Testing Polymorphic Insertion Operator ==\n" << baseReference
      << endl;
    cout << "== Testing Polymorphic Rows and Columns Accessors ==\n" <<
      "Rows: " << baseReference.rows() << "  Columns: " << baseReference.columns()
      << endl << endl;

    cout << "== Testing Polymorphic row access via projection operator ==\n" <<
      "matrix[0] = " << baseReference[0] << endl << endl;

    MathMatrix2D<double> augmented = 
      GaussianElimination<double>::augmentedMatrix(vandermonde, yValues);
    IMathMatrix<double>& baseReference2 = augmented;
    cout << "== Testing Polymorphic Equality Operator ==\n" <<
      "Augmented == Original?: " << (baseReference == baseReference2) <<
      endl << endl;

    cout << "== Building Augmented Matrix for Polynomial Interpolation ==\n";
    cout << endl << augmented << endl;

    try {
      MathVector<double> gaussianNoPivot = gaussSolver(vandermonde, yValues);
      cout << gaussianNoPivot << endl;

      MathVector<double> gaussianWithPivot = gaussSolver(vandermonde, yValues, true);
      cout << gaussianWithPivot << endl;
    } 
    catch (std::exception e)
    {
      cout << e.what() << "\nQuitting Driver." << endl;
      return 0;
    }

  }
  else 
  {
    cout << "Unable to Open file, exiting..." << argv[1] << "\n";
    return 1;
  }
  inputFile.close();
  return 0;
}
