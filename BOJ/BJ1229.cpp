#pragma warning (disable:4996)
#include<iostream>
#include<cstdio>
using namespace std;
bool video[64][64];
int N;

bool checkWhite(int sy, int sx, int len) {
	for (int i = sy; i < sy+len; ++i) {
		for (int j = sx; j < sx+len; ++j) {
			if (video[i][j] == 1)	return false;
		}
	}
	return true;
}

bool checkBlack(int sy, int sx, int len) {
	for (int i = sy; i < sy+len; ++i) {
		for (int j = sx; j < sx+len; ++j) {
			if (video[i][j] == 0)	return false;
		}
	}
	return true;
}

void compression(int sy, int sx, int len) {
	
	if (checkWhite(sy, sx, len)) { // 모든 영역이 1인경우 => 출력
		cout << 0;
	}
	else if (checkBlack(sy, sx, len)) { // 모든 영역이 0인경우 => 출력
		cout << 1;
	}
	else { // 섞여있는 경우
		cout << "(";
		int half = len / 2;
		compression(sy, sx, half); 		// 0 , 0
		compression(sy, sx + half, half); 		// 0, 1
		compression(sy + half, sx, half); 		// 1, 0
		compression(sy + half, sx + half, half); 		// 1, 1
		cout << ")";
	}
}
int main(void)
{
	scanf("%d\n", &N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%1d", &video[i][j]);
		}
	}
	compression(0, 0, N);
	return 0;
}