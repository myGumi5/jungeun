#include <iostream>
using namespace std;
long long sum(int n) { return n*(n+1)/2;} // 1~n까지 등차수열 합
int main(void)
{
    int N, L;
    long long x, tmp;
    cin >> N >> L;

    while(L <= 100) {
        x = 1;
        tmp = N-sum(L-1);
        if (tmp < 0) break;
        if(tmp%L == 0) { // 답
            x = tmp/L;
            for(long long i=x; i<x+L; ++i) {
                cout << i << " ";
            }
            cout << "\n";
            return 0;
        } else { // L 증가하며 확인
            L++;
        }
        
    }
    cout << -1 << "\n";
    return 0;
}