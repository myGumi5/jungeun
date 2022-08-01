#include <iostream>
#include <algorithm>
using namespace std;
int triangle[501][501];
int main(void)
{
    int n, max_result=0;
    cin >> n;

    for(int i=1; i<= n; ++i) {
        for (int j=1; j<=i; ++j) {
            cin >> triangle[i][j];
        }
    }

    for (int i=2; i<=n; ++i) {
        for (int j=1; j<=i; ++j) {
            if (j==1) triangle[i][j] += triangle[i-1][j]; // 가장 왼쪽
            else if (j==i)  triangle[i][j] += triangle[i-1][j-1]; // 가장 오른쪽
            else triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j]); // 사이값
        }
    }

    for(int i=1; i<=n; ++i) 
        if (triangle[n][i] > max_result)   max_result = triangle[n][i];
        
    cout << max_result << "\n";
}