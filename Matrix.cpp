#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "vector"
#include "Matrix.hpp"

using namespace std;
using namespace zich;

void Matrix::check_matrix_size(const Matrix &mat1, const Matrix &mat2)
{
    if (mat1.row != mat2.row or mat1.col != mat2.col)
    {
        throw std::invalid_argument("rows and cols not equals");
    }
}

void Matrix::check_building_matrix(const std::vector<double> &matri, int row, int col)
{
    if (row * col != matri.size())
    {
        throw std::invalid_argument("oopsi");
    }
    if (row < 1 or col < 1)
    {
        throw std::invalid_argument("row and col cannot be negative");
    }
}

void Matrix::check_valid_mult(const Matrix &mat1, const Matrix &mat2)
{
    if (mat1.col != mat2.row)
    {
        throw std::logic_error("error");
    }
}

Matrix::Matrix(int row, int col)
{
    this->row = row;
    this->col = col;
}

Matrix::Matrix(std::vector<double> matri, int row, int col)
{
    check_building_matrix(matri, row, col);
    this->col = col;
    this->row = row;
    for (unsigned int i = 0; i < row * col; i++)
    {
        mat.push_back(matri[i]);
    }
}

//-----------------------------
// Arithmetic Operators
//-----------------------------

Matrix Matrix::operator-()
{
    Matrix mat1(this->row, this->col);

    for (unsigned int i = 0; i < this->mat.size(); i++)
    {
        mat1.mat.push_back((-1) * (this->mat[i]));
    }
    return mat1;
}

Matrix Matrix::operator-(const Matrix &mat1)
{
    check_matrix_size(*this, mat1);
    Matrix matr(this->row, this->col);
    for (unsigned int i = 0; i < this->mat.size(); i++)
    {
        matr.mat.push_back(this->mat[i] - mat1.mat[i]);
    }
    return matr;
}
void Matrix::operator-=(const Matrix &mat1)
{
    check_matrix_size(*this, mat1);
    for (unsigned int i = 0; i < this->mat.size(); i++)
    {
        this->mat[i] -= mat1.mat[i];
    }
}

Matrix Matrix::operator+()
{
    Matrix matr(this->row, this->col);
    for (unsigned int i = 0; i < this->mat.size(); i++)
    {
        matr.mat.push_back(this->mat[i]);
    }
    return matr;
}

Matrix Matrix::operator+(const Matrix &mat1)
{
    check_matrix_size(*this, mat1);
    Matrix matr(this->row, this->col);
    for (unsigned int i = 0; i < this->mat.size() ;i++)
    {
        matr.mat.push_back(this->mat[i] + mat1.mat[i]);
    }
    return matr;
}
void Matrix::operator+=(const Matrix &mat1)
{
    check_matrix_size(*this, mat1);
    for (unsigned int i = 0; i < this->mat.size(); i++)
    {
        this->mat[i] += mat1.mat[i];
    }
}

//-----------------------------
// Comparison Operators
//-----------------------------

bool zich::Matrix::operator!=(const Matrix &mat1)
{
    for (unsigned int i = 0; i < this->mat.size(); i++)
    {
        if (this->mat[i] != mat1.mat[i])
        {
            return true;
        }
    }
    return false;
}
bool zich::Matrix::operator==(const Matrix &mat1)
{
    for (unsigned int i = 0; i < this->mat.size(); i++)
    {
        if (this->mat[i] != mat1.mat[i])
        {
            return false;
        }
    }
    return true;
}

bool zich::Matrix::operator<=(Matrix &mat1)
{
    bool ans = false;
    if (this->sum() <= mat1.sum())
    {
        ans = true;
    }

    return ans;
}
bool zich::Matrix::operator>=(Matrix &mat1)
{
    bool ans = false;
    if (this->sum() <= mat1.sum())
    {
        ans = true;
    }

    return ans;
}

int zich::Matrix::sum()
{

    int res = 0;
    for (unsigned int i = 0; i < this->mat.size(); i++)
    {
        res += this->mat[i];
    }
    return res;
}

bool zich::Matrix::operator<(Matrix &mat1)
{
    bool ans = false;
    if (this->sum() < mat1.sum())
    {
        ans = true;
    }

    return ans;
}
bool zich::Matrix::operator>(Matrix &mat1)
{
    bool ans = false;
    if (this->sum() > mat1.sum())
    {
        ans = true;
    }

    return ans;
}
//-----------------------------
// Increment Decrement Operators
//-----------------------------

void Matrix::operator--()
{
    for (unsigned int i = 0; i < this->mat.size(); i++)
    {
        this->mat[i] -= 1;
    }
}

void Matrix::operator--(const int d)
{
    for (unsigned int i = 0; i < this->mat.size(); i++)
    {
        this->mat[i] -= 1;
    }
}

void Matrix::operator++()
{
    for (unsigned int i = 0; i < this->mat.size(); i++)
    {
        this->mat[i] += 1;
    }
}

void Matrix::operator++(const int d)
{
    for (unsigned int i = 0; i < this->mat.size(); i++)
    {
        this->mat[i] += 1;
    }
}

//-----------------------------
// Friend Operators
//-----------------------------

Matrix Matrix::operator*(const Matrix &mat1)
{
    double s = 0;
    check_valid_mult(*this, mat1);
    Matrix matr(this->row, mat1.col);
    for (unsigned int i = 0; i < this->mat.size(); i++)
    {
        matr.mat.push_back(0);
    }

    for (unsigned int i = 0; i < this->row; i++)
    {
        for (unsigned int j = 0; j < mat1.col; j++)
        {
            s = 0;
            for (unsigned int k = 0; k < this->col; k++)
            {
                matr.mat[i * (unsigned int)matr.col + j] += this->mat[i * (unsigned int)this->col + k] * mat1.mat[k * (unsigned int)mat1.col + j];
            }
        }
    }

    return matr;
}

void Matrix::operator*=(const Matrix &mat1)
{
    check_valid_mult(*this, mat1);
    Matrix matr(this->row, mat1.col);
    for (unsigned int i = 0; i < this->mat.size(); i++)
    {
        matr.mat.push_back(0);
    }

    for (unsigned int i = 0; i < this->row; i++)
    {
        for (unsigned int j = 0; j < mat1.col; j++)
        {
            for (unsigned int k = 0; k < this->col; k++)
            {
                matr.mat[i * (unsigned int)matr.col + j] += this->mat[i * (unsigned int)this->col + k] * mat1.mat[k * (unsigned int)mat1.col + j];
            }
        }
    }
    this->mat=matr.mat;
}
void Matrix::operator*=(const double d)
{
    for (unsigned int i = 0; i < this->mat.size(); i++)
    {
        this->mat[i] = (d) * (this->mat[i]);
    }
}

//-----------------------------
// I/O Operators
//-----------------------------

namespace zich
{

    Matrix operator*(double d, const Matrix &mat1)
    {
        vector<double> ans;
        for (unsigned int i = 0; i < mat1.mat.size(); i++)
        {
            ans.push_back((d) * (mat1.mat[i]));
        }
        return Matrix(ans, mat1.row, mat1.col);
    }

    ostream &operator<<(ostream &out, const Matrix &num)
    {
        string res;
        for (unsigned int i = 0; i < num.row; i++)
        {
            res += '[';
            for (unsigned int j = 0; j < num.col; j++)
            {
                res += to_string(num.mat[i * (unsigned int)num.col + j]);
                if (j != num.col - 1)
                {
                    res += " ";
                }
            }
            res += ']';
            res += "\n";
        }

        return out << res;
    }

}
