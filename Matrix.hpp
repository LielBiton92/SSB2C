#include <iostream>
#include "vector"
namespace zich
{

    class Matrix
    {
    private:
         int row;
         int col;

    public:
             std::vector<double> mat;

        Matrix(int, int);
        Matrix();
        Matrix(std::vector<double>, int row, int col);
        static void check_matrix_size(const Matrix &, const Matrix &);
        static void check_valid_mult(const Matrix &, const Matrix &);
        static void check_building_matrix(const std::vector<double> &, int, int);
        int sum();

        //-----------------------------
        // Arithmetic Operators
        //-----------------------------

        Matrix operator-();
        Matrix operator-(const Matrix &);
        Matrix operator-=(const Matrix &);

        Matrix operator+();
        Matrix operator+(const Matrix &);
        Matrix operator+=(const Matrix &);

        //-----------------------------
        // Friend Comparison Operators
        //-----------------------------

        bool operator!=(const Matrix &mat1);
        bool operator==(const Matrix &mat1);
        bool operator<=(Matrix &mat1);
        bool operator>=(Matrix &mat1);
        bool operator<(Matrix &mat1);
        bool operator>(Matrix &mat1);

        //-----------------------------
        // Increment Decrement Operators
        //-----------------------------

        Matrix operator--();
        Matrix operator++();
        Matrix operator--(const int);
        Matrix operator++(const int);

        //-----------------------------
        // I/O Operators
        //-----------------------------
        friend std::ostream &operator<<(std::ostream &out, const Matrix &num);
        friend std::istream &operator>>(std::istream &in, Matrix &mat);

        //-----------------------------
        // Friend Operators & mult
        //-----------------------------

        Matrix operator*(const Matrix &);
        Matrix operator*=(const double);
        Matrix operator*=(const Matrix &);
        friend bool operator==(const Matrix &mat1 , const Matrix &mat2);
        std::vector<std::string> split(std::string const &str, char delim);
        friend Matrix operator*(double, const Matrix &);
        friend Matrix operator*(const Matrix &, double);

        std::string ostreamToString(std::istream &os);
    };

}
