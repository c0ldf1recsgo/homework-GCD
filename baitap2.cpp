#include <iostream>
#include <math.h>
using namespace std;

int GCD(int, int);
void findAB(int &, int &, int, int);

int GCD(int a, int b){
    if (b == 0) 
        return a; 
    return GCD(b, a % b); 
}

void findAB(int &a, int &b, int x, int y){
    if(y == 0){
        a = 1;
        b = 0;
        return;
    }

    int a1, b1;
    findAB(a1, b1, y, x % y);
    a = b1;
    b = a1 - (x / y) * b1;
}

int main(){
    int a, b, gcd;
    int x = 1914;
    int y = 899;
    if(x >= y){
        findAB(a, b, x, y);
        gcd = GCD(x, y);
    }
    else {
        findAB(a, b, y, x);
        gcd = GCD(y, x);
    }   
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "GCD(" << x << "," << y << ") = " << gcd << endl;

    return 0;
}