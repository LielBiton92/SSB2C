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
      vector<double> test1 = {1,2,3,4};
    vector<double> test2= {5,6,7,8};
        vector<double> test3= {5,6,7,8,9,10}; //2*3
  
   Matrix a{identity, 3, 3}; 
   Matrix b{arr, 3, 3};
   Matrix c{test1 ,2 ,2};
   Matrix d{test2, 2 ,2};
   Matrix e{test3,2,3};
   
       vector<double>testcase2 = {1,2,3,4,5,6,7,8,9};
      Matrix B{testcase2, 3 ,3};
    Matrix A{testcase2 , 3 ,3};

      Matrix f ={{0,0,0,0,0,0,0,0,0},3,3};
      A*=2;
    Matrix f_ans ={{1,1,1,1,1,1,1,1,1},3,3};
    cout << a-b;
  
  
  
   return 0;
}
