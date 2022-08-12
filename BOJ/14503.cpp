#include <iostream>
using namespace std;
int map[50][50];
int N, M, r, c;
bool backward(int d) {
    switch(d) {
    case 0: if(r+1 < N && map[r+1][c]!=1) {++r; return true; } else return false; // 북쪽에서 후진 (y 증가) r
    case 1: if(c-1 >= 0 && map[r][c-1]!=1) {--c; return true;} else return false; // 동쪽에서 후진 (x감소)c
    case 2: if(r-1 >= 0 && map[r-1][c]!=1) {--r; return true;} else return false; // 남쪽에서 후진 (y 감소)r
    case 3: if(c+1 < M && map[r][c+1]!=1) { ++c; return true;} else return false; // 서쪽에서 후진 (x증가)c
    }
    return false;
}
int main(void)
{
    int d;
    cin >> N >> M; //N:세로, M:가로
    cin >> r >> c >> d; // 청소기 좌표(r,c), 방향 d (0:북, 1:동, 2:남, 3:서)
    for(int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> map[i][j];
        }
    }
    int new_x = 0, new_y = 0, new_d = 0;
    int dx[] = { 0, 1, 0, -1 };
    int dy[] = { -1, 0, 1, 0 };
    int cnt = 0; 
    bool forward_flag = false;
    while(true) {
        forward_flag = false; // 전진 가능한지 저장
        if(map[r][c] == 0) { // 현재위치 0 : 청소
            map[r][c] = 2; ++cnt;
        }
        for(int i=0; i<4; ++i) { // 왼쪽으로 돌면서 탐색
            (d == 0) ? d = 3 : d = d-1; // 방향 왼쪽으로 돌기           
            new_x = c+dx[d];  new_y = r+dy[d];
            if(new_x >= 0 && new_y >= 0 && new_x < M && new_y < N && (map[new_y][new_x] == 0)) { // 다음 청소방향으로 이동
                c = new_x;  r = new_y;
                forward_flag = true;
                break;
            }
        }
        if(!forward_flag) { // 모두 벽이거나 모두 청소된 경우 => 방향 유지, 후진 한칸
            if(!backward(d)) break;   // 후진 불가능한 경우 바로 break
        }
    }
    cout << cnt << "\n";
    return 0;
}