#include <iostream>
#include <cstring>
using namespace std;
int N, M, map_y, map_x;
int map[20][20];
int dice[7];

void updateMap(int y, int x) { // 지도 업데이트 해줌
    if (map[y][x]) { // 지도 칸이 0: 주사위 바닥값 바꾸고 지도 0으로 바꾸기
        dice [6] = map[y][x];
        map[y][x] = 0;
    } else { // 지도 칸이 !0 : 주사위 바닥값으로 맵 갱신, 지도 칸 0으로 변경
        map[y][x] = dice[6];
    }
    // 새로운 주사위 위치 저장
    map_y = y;
    map_x = x;
    return;
}
bool roll(int direction, int y, int x) {
    int dice_tmp[7];
    memcpy(dice_tmp, dice, sizeof(int)*7);
    switch (direction) {
    case 1: // 동
        if(x+1 >= M)    return false; //갈 수 있는 범위인지 확인
        dice[1] = dice_tmp[4];
        dice[3] = dice_tmp[1];
        dice[6] = dice_tmp[3];
        dice[4] = dice_tmp[6];
        updateMap(y, x+1);
        break;
    case 2: // 서
        if (x-1 < 0)    return false;
        dice[6] = dice_tmp[4];
        dice[4] = dice_tmp[1];
        dice[1] = dice_tmp[3];
        dice[3] = dice_tmp[6];
        updateMap(y, x-1);
        break;
    case 3: // 북
        if (y-1 < 0)   return false;
        dice[6] = dice_tmp[2];
        dice[2] = dice_tmp[1];
        dice[1] = dice_tmp[5];
        dice[5] = dice_tmp[6];
        updateMap(y-1, x);
        break;
    case 4: // 남
        if (y+1 >= N)    return false;
        dice[1] = dice_tmp[2];
        dice[5] = dice_tmp[1];
        dice[6] = dice_tmp[5];
        dice[2] = dice_tmp[6];
        updateMap(y+1, x);
        break;
    }
    return true;
}

int main(void)
{  
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int K;
    cin >> N >> M >> map_y >> map_x >> K;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            cin >> map[i][j];
        }
    }
    int tmp;
    for(int i=0; i<K; ++i) {
        cin >> tmp;
        if (roll(tmp, map_y, map_x))
            cout << dice[1] << "\n"; //상단값 출력
    }
    return 0;
}