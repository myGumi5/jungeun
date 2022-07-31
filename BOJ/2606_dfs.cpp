#include <iostream>
using namespace std;
bool visited[101];
int N, sum;
bool computer[101][101];
void dfs(int num) {
    visited[num] = true;
    for(int i=1; i<=N; ++i) {
        if (computer[num][i] && !visited[i]) {
            dfs(i);
            ++sum;
        }       
    }
}
int main(void)
{
    int M, a, b;
    cin >> N >> M;
    for(int i=0; i<M; ++i) {
        cin >> a >> b;
        computer[a][b] = computer[b][a] = true;
    }
    dfs(1);
    cout << sum << "\n";
    return 0;
}