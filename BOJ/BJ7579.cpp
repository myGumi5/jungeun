#include <iostream>
using namespace std;
int N, M, A[101], C[101], sum, DP[101][10001]; // C의 최댓값(100) * 최대갯수(199) = 10000
int max(int a, int b) {
    return a < b ? b : a;
}
int main(void)
{
    int tmp;
    cin >> N >> M;
    for(int i=1; i<=N; ++i) cin >> A[i]; // 현재 사용중인 메모리
    for(int i=1; i<=N; ++i) {cin >> C[i]; sum += C[i];}; // 비활성화 했을 경우 비용
    for(int i=1; i<=N; ++i) { // 넣을 수 있는 앱 번호 ~ i (배낭 : n)
        for(int j=0; j<=sum; ++j) { // 비용(배낭: 넣을 수 있는 무게 k)
            if(C[i] <= j) { // 비용 충분한 경우
                DP[i][j] = max(DP[i-1][j], DP[i-1][j-C[i]]+A[i]);
            } else {
                DP[i][j] = DP[i-1][j];
            }
        }
    }
    for(int i=0; i<=sum; ++i) {
        if (DP[N][i] >= M) { // 최소비용을 만족하는 가장 첫 값 출력 후 종료
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}