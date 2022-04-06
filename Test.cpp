#include "doctest.h"
#include "Matrix.hpp"
#include "string"
#include "algorithm"
using namespace std;
using namespace zich;

TEST_CASE("Good")
{
    bool ans = 0;
    vector<double> testcase = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<double> testcase2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<double> test1 = {1, 2, 3, 4};
    vector<double> test2 = {5, 6, 7, 8};
    vector<double> test1test2 = {19, 22, 43, 50};
    Matrix A{testcase, 3, 3};
    Matrix B{testcase2, 3, 3};
    Matrix t1{test1, 2, 2};
    Matrix t2{test2, 2, 2};
    Matrix C{test1test2, 2, 2};
    ans = (A >= B);
    cout << ans;
    CHECK(ans == true);
    ans = A <= B;
    CHECK(ans == true);
    A *= 2;
    ans = A > B;
    CHECK(ans == true);
    ans = t1 * t2 == C;
    CHECK(ans == true);
    ++t1;
    ans = t1 * t1 != C;
    CHECK(ans == true);
    Matrix f = {{0, 0, 0, 0, 0, 0, 0, 0, 0}, 3, 3};
    Matrix f_ans = {{1, 1, 1, 1, 1, 1, 1, 1, 1}, 3, 3};
    Matrix G = -B - B;
    ans = A - G == f;
    CHECK(ans == false);
    f++;
    ans = f == f_ans;
    CHECK(ans == true);
    Matrix mat4{{1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3};
    Matrix mat5{{1, 2, 3, 4, 5, 6}, 2, 3};
    ans = mat5 * mat4 == mat5 * mat4;
    CHECK(ans == true);

    std::vector<double> identity = {1, 2, 0, 5, 1, 0, -1, 0, 1};
    std::vector<double> arr = {3, 0, 0, 0, 3, -3, 2, 0, 3};
    Matrix a1{identity, 3, 3};
    Matrix b1{arr, 3, 3};
    Matrix c1{{3, 6, -6, 15, 3, -3, -1, 0, 3}, 3, 3};
    Matrix d1{{4,2,0,5,4,-3,1,0,4}, 3, 3};
    Matrix e1{{-2, 2, 0, 5, -2, 3, -3, 0, -2}, 3, 3};
    ans = a1 * b1 == c1;
    CHECK(ans == true);
    ans = a1 + b1 == d1;
    CHECK(ans == true);
    ans = a1 - b1 == e1;
    CHECK(ans == true);
    mat5++;
    Matrix mat5a{{2, 3, 4, 5, 6, 7}, 2, 3};
    ans = mat5 == mat5a;
    CHECK(ans == true);
}
TEST_CASE("goodinput"){

}

TEST_CASE("Bad")
{
    bool res = 0;
    Matrix mat{{1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3};
    Matrix mat2{{1, 2, 3, 4, 5, 6}, 2, 3};
    CHECK_THROWS(mat + mat2);
    CHECK_THROWS(mat - mat2);
    CHECK_THROWS(mat += mat2);
    CHECK_THROWS(mat * mat2);
    CHECK_THROWS(mat2 - mat);
    CHECK_THROWS(mat2 + mat);
    std::vector<double> mat6vector;
    for (unsigned int i = 0; i < 99; i++)
    {
        mat6vector.push_back(i);
    }
    Matrix mat6{mat6vector, 33, 3};
    CHECK_THROWS(mat6 * mat2);
    CHECK_THROWS(mat6 + mat2);
    CHECK_THROWS(mat6 - mat2);
}


