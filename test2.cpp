#include "iostream"
#include "vector"
using namespace std;

int main(int argc, char const *argv[])
{
vector<vector<int> > vec( 3 , vector<int> (4, 0)); 
for(int i = 0 ; i < 3 ; i++){
    cout <<endl;
    for(int j = 0 ; j <4 ; j++){
        cout << vec.at(i).at(j);
    }
}
    return 0;
}
