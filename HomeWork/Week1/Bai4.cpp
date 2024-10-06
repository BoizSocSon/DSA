#include <iostream>

using namespace std;

int gcd(int a, int b) { 
    if(b == 0)
        return a;
    else 
        return gcd(b, a % b);
}

void reduce(int *a, int *b){
    int divisor = gcd(*a, *b);
    *a /= divisor;
    *b /= divisor;
}

int main(){
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    reduce(&a, &b);
    cout << "Reduced form of " << a << "/" << b << endl;
    return 0;
 
}