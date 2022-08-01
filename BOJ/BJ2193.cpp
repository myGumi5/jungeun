#include <iostream>
using namespace std;

long long cnt[91];
int main (void)
{
    int N;
    cin >> N;

    cnt[1]=1; cnt[2]=1;
    for(int i=3; i<=N; ++i) {
        cnt[i] = cnt[i-2]+cnt[i-1];
    }
    cout << cnt[N] << "\n";

    return 0;
}