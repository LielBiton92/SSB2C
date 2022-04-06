#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
#include "Matrix.hpp"
using namespace zich;

int main(int argc, char const *argv[])
{

    std::vector<double> identity = {1, 2, 0, 5, 1, 0, -1, 0, 1};
    std::vector<double> arr = {3, 0, 0, 0, 3, -3, 2, 0, 3};
    Matrix a1{identity, 3, 3};
    Matrix b1{arr, 3, 3};

    cout <<a1+b1;
  return 0;
}
