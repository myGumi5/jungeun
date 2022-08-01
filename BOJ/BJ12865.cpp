#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, K;
int bag[101][100001];
int main(void)
{
    int W, V, tmp1, tmp2, weight;
    vector <pair<int,int>> v;
    cin >> N >> K;
    v.push_back(make_pair(0, 0));
    for (int i=0; i<N; ++i) {
        cin >> tmp1 >> tmp2; // <무게, 가치>
        v.push_back(make_pair(tmp1, tmp2));
    }
    for(int i=1; i<=N; ++i) { // 확인할 물건 번호
        for (int j=1; j<=K; ++j) { // 가방에 담을 수 있는 무게
            weight = j - v[i].first; // 현재 물건 넣고 남는 무게
            if (weight >= 0) bag[i][j] = max(bag[i-1][j], bag[i-1][weight] + v[i].second);
            else  bag[i][j] = bag[i-1][j]; 
        }
    }
    cout << bag[N][K] << "\n";
    return 0;
}