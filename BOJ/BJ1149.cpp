#include <iostream>
#include <algorithm>
using namespace std;

int house[1001][3];

int main(void)
{
    int N, tmp;
    cin >> N;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<3; ++j) {
            cin >> house[i][j]; 
        }
    }

    for(int i=1; i<N; ++i) {
        house[i][0] += min(house[i-1][1], house[i-1][2]); // 
        house[i][1] += min(house[i-1][0], house[i-1][2]); // 
        house[i][2] += min(house[i-1][0], house[i-1][1]); // 
    }
    cout << min(min(house[N-1][0], house[N-1][1]), house[N-1][2]) << "\n";
    
    return 0;
}