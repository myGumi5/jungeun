#include <iostream>
using namespace std;
bool adj[100][100];
int main(void) {
    int n;
    cin >> n;
    for(int i=0; i<n; ++i) 
        for(int j=0; j<n; ++j) 
            cin >> adj[i][j];
    
    for(int k=0; k<n; ++k) { // 거쳐갈 노드
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (adj[i][k]&&adj[k][j]) // 거쳐가는 경로 있는경우
                    adj[i][j] = 1;
            }
        }
    }
    for(int i=0; i<n; ++i, cout<<"\n") //정답 출력
        for(int j=0; j<n; ++j) 
            cout << adj[i][j] << " ";
    return 0;
}