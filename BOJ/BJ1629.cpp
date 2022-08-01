#include <iostream>
using namespace std;

long long my_pow(int a, int b, int c) {
    if (b==0)   return 1;
    else if (b==1) return a%c;
    long long tmp = my_pow(a, b/2, c);
    if (b%2==0) return tmp%c*tmp%c;
    else return a%c*tmp%c*tmp%c;
}

int main(void) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << my_pow(a,b,c) << "\n";
    return 0;
}