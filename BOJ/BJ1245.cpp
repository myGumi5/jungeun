#include <iostream>
#include <queue>
#include <utility>
#include <cstdlib>
using namespace std;
int N, M;
bool check = true; // 가장 높은지 확인
int mountain[102][72];
bool visited[102][72];

void dfs(int x, int y) {
    visited[x][y] = true;
    int height = mountain[x][y];
    int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
    int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};
    
    for(int i=0; i<8; ++i) {
        int new_x = x+dx[i];
        int new_y = y+dy[i];
        int cmp = mountain[new_x][new_y];

        if(height < cmp)    check = false;
        if((abs(height-cmp) ==0) && !visited[new_x][new_y]) {
            dfs(new_x, new_y);
        }
    }
}
int main(void)
{
    int peak = 0;
    pair<int, int> start;
    cin >> N >> M;
    for(int i=1; i<=N; ++i) {
        for (int j=1; j<=M; ++j) {
            cin >> mountain[i][j];
        }
    }
    for(int i=1; i<=N; ++i) {
        for (int j=1; j<=M; ++j, check = true) {
            if(!visited[i][j] && mountain[i][j]!=0) {
                dfs(i , j);
                if(check)   peak++;
            }
        }
    }
    cout << peak << "\n";
    return 0;
}