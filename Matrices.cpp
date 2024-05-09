#include "Matrices.h"

namespace Matrices
{
    ///Add each corresponding element.
    ///usage:  c = a + b;
    Matrix operator+(const Matrix& a, const Matrix& b)
    {
        Matrix c(a.getRows(), a.getCols());
        if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
        {
            throw runtime_error("Error: dimensions must agree");
        }
        for (int i = 0; i < a.getRows(); i++) {
            for (int j = 0; j < a.getCols(); j++) {
                c(i, j) = a(i, j) + b(i, j);}
        }
        return c;
    }

    ///Matrix multiply.  See description.
    ///usage:  c = a * b;
    Matrix operator*(const Matrix& a, const Matrix& b)
    {
        Matrix c(a.getRows(), b.getCols());
        //int n = a.getCols();
        if (a.getCols() != b.getRows())
        {
            throw runtime_error("Error: dimensions must agree");
        }
        for (int i = 0; i < c.getRows(); i++) {
            for (int j = 0; j < c.getCols(); j++) {
                c(i, j) = 0;
                for (int e = 0; e < a.getCols(); e++) {
                    c(i, j) += (a(i, e) * b(e, j));
                }
            }
        }

        return c;
    }

    ///Matrix comparison.  See description.
    ///usage:  a == b
    bool operator==(const Matrix& a, const Matrix& b)
    {
        if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
        {
            return false;
        }
        for (int i = 0; i < a.getRows(); i++) {
            for (int j = 0; j < a.getCols(); j++) {
                if (abs(a(i, j) - b(i, j)) < 0.001) {
                    return true;
                }
            }
        }
        return false;
    }

    ///Matrix comparison.  See description.
    ///usage:  a != b
    bool operator!=(const Matrix& a, const Matrix& b)
    {
        if (a.getRows() == b.getRows() && a.getCols() == b.getCols()) {
            for (int i = 0; i < a.getRows(); i++) {
                for (int j = 0; j < a.getCols(); j++) {
                    if (abs(a(i, j) - b(i, j)) < 0.001) {
                        return false;
                    }

                }
            }
        }
        return true;
    }

    ///Output matrix.
    ///Separate columns by ' ' and rows by '\n'
    ostream& operator<<(ostream& os, const Matrix& a) {
        for (int i = 0; i < a.getRows(); i++) {
            os << "\n";
            for (int j = 0; j < a.getCols(); j++) {
                os << a(i, j) << " ";
            }
        }
        return os;
    }


RotationMatrix::RotationMatrix(double theta): Matrix(2,2)
	{
		a[0][0] = cos(theta);
		a[0][1] = -sin(theta);
		a[1][0] = sin(theta);
		a[1][1] = cos(theta);
    }
ScalingMatrix::ScalingMatrix(double scale): Matrix(2,2)
    {
        a[0][0] = scale;
		a[0][1] = 0;
		a[1][0] = 0;
		a[1][1] = scale;
    }

/*TranslationMatrix::TranslationMatrix(double xShift, double yShift, int nCols): Matrix(2,nCols)
    {
        for (int j=0; j<nCols; j++){
            a[0][j] = xShift;
            a[1][j] = yShift;
        }
    }*/
  
Matrix operator+(const TranslationMatrix& T, const Matrix& b)
        {
        Matrix c(b.getRows(), b.getCols());

        for (int i = 0; i < b.getRows(); i++) {
            for (int j = 0; j < b.getCols(); j++) {
                c(i, j) = b(i, j) + T(i, j);}
        }
        return c;
    }


}