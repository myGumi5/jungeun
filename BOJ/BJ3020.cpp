#include <iostream>
using namespace std;

int obstacle1[500001], obstacle2[500001];// 석순, 종유석
int main(void)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, H, min_val = 99999999, cnt=0, height;
    cin >> N >> H;
    
    for (int i=1; i<=N; ++i) {
        cin >> height;
        if (i%2==0) obstacle1[height]++; //짝수: 석순
        else obstacle2[height]++;  // 홀수: 종유석
    }

    for(int i=H; i>0; --i) { // 누적합 구하기
        obstacle1[i-1] += obstacle1[i];
        obstacle2[i-1] += obstacle2[i];
    }

    for (int i=1; i<=H; ++i) // 장애물 최소 부수는 개수 구하기, 종유석은 뒤에서 확인
        if (min_val > obstacle1[i]+obstacle2[H-i+1]) min_val = obstacle1[i]+obstacle2[H-i+1];
    for (int i=1; i<=H; ++i) // 최소 장애물 구간 개수 구하기
        if (min_val == obstacle1[i]+obstacle2[H-i+1])  cnt ++;
    
    cout << min_val <<" " << cnt <<"\n";

    return 0;
}