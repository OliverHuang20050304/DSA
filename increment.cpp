#include <iostream>
using namespace std;

int main(){
    int i = 5;
    int j = i++; // j == 5
    cout << "使用後置運算子時，j = " << j << endl;

    i = 5;
    j = ++i; // j == 6
    cout << "使用前置運算子時，j = " << j << endl;


    return 0;
}