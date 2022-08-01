#include <iostream>
#define INF 9999999
using namespace std;
int bus[101][101];
int main(void)
{   
    int n, m, a,b,c;
    cin >> n >> m;
    for(int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            if (i==j) bus[i][j] = 0;
            else bus[i][j] = INF;
        }
    }
    for(int i=0; i<m; ++i) {
        cin >> a >> b >> c;
        if(bus[a][b] > c) // 기존노선보다 더 비용 적을경우만 넣기
            bus[a][b] = c;
    }

    for(int k=1; k<=n; ++k) { // 거쳐가는 노드
        for(int i=1; i<=n; ++i) { // 출발지
            for(int j=1; j<=n; ++j) { // 목적지
                if(bus[i][k]+bus[k][j] < bus[i][j])
                    bus[i][j] = bus[i][k]+bus[k][j];
            }
        }
    }

    for(int i=1; i<=n; ++i, cout<<"\n") {
        for (int j=1; j<=n; ++j) {
            if (bus[i][j] >= INF) cout << 0 << " ";
            else cout << bus[i][j] << " ";
        }
    }
    return 0;
}