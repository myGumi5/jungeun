#include <iostream>
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    } else if (n==2) {
        cout << 2 << "\n";
        return 0;
    }

    int tile[1001] = {0, 1, 2, };

    for (int i=3; i<=n; ++i) {
        tile[i] = (tile[i-1]+tile[i-2])%10007;
    }

    cout << tile[n]%10007 << "\n";

    return 0;
}