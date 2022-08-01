#include <iostream>
#include <queue>
using namespace std;
int N, sum;
queue<int> q;
bool computer[101][101];
bool visited[101];
void bfs(int num) {
    visited[num] = true; // 바이러스 시작하는 1
    q.push(num);
    while(!q.empty()) {
        num = q.front();
        q.pop();
        // cout << "방문: "<< num << endl;
        for(int i=1; i<=N; ++i) {
            if(computer[num][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
                ++sum;
            }
        }
        
    }
}
int main(void)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M, a, b;
    cin >> N >> M;
    for(int i=0; i<M; ++i) {
        cin >> a >> b;
        computer[a][b] = computer[b][a] = true;
    }
    bfs(1);
    cout << sum << "\n";
    return 0;
}