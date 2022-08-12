#include <iostream>
#include <algorithm>
using namespace std;
int N, M, K, max_cnt; // 세로 N, 가로 M, 음식물 개수 K
bool aisle[101][101];
int visited[101][101];
int ans[101];
void dfs(int flag_y, int flag_x, int y, int x) {
    int dy[4] = {1,-1,0,0}; int dx[4] = {0,0,-1,1};
    int new_x, new_y;
    for(int i=0; i<4; ++i) {
        new_y = y+dy[i]; new_x = x+dx[i];
        if(new_y <= N && new_y >=1 && new_x >=1 && new_x <= M && !visited[new_y][new_x] && aisle[new_y][new_x]) {
            visited[new_y][new_x] = visited[flag_y][flag_x]; // 같은 음식물인지를 알기위함
            dfs(flag_y, flag_x, new_y, new_x);
        }
    }
}
int main(void){
    cin >> N >> M >> K;
    int r, c, cnt = 0;
    for(int i=0; i<K; ++i) { // r:세로, c:가로
        cin >> r >> c;
        aisle[r][c] = true;
    }

    int ans_flag = 1;
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=M; ++j) {
            if(aisle[i][j] && !visited[i][j]) {
                visited[i][j] = ans_flag++;
                dfs(i, j, i, j);
            }
        }
    }

    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=M; ++j) {
            ans[visited[i][j]] += 1; // 같은 음식물의 최대개수 카운트
        }
    }

    cout << *max_element(ans+1, ans+ans_flag) << "\n";
    return 0;
}