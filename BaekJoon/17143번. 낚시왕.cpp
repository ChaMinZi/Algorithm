#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#define MAXSZ 102

using namespace std;

struct shark {
	int sId;
	int r, c, speed, dir, size;
};

int board[MAXSZ][MAXSZ];
int dr[] = { -1,0,1,0 }, dc[] = { 0,1,0,-1 };
vector<shark> sharkList;
queue<shark> existSharkList;

pair<int, int> king = { 0,0 };

int R, C, M;

bool compare(shark a, shark b) {
	return a.size > b.size;
}

bool isPossi(int r, int c) {
	return (r > 0 && r <= R && c > 0 && c <= C);
}

int findNearShark() {
	for (int r = 1; r <= R; r++) {
		if (board[r][king.second] > -1)
			return board[r][king.second];
	}
	return -1;
}

void moveShark() {
	queue<shark> tempList;
	int tempBoard[MAXSZ][MAXSZ];
	for (int i = 0; i <= R; i++)
		for (int j = 0; j <= C; j++)
			tempBoard[i][j] = -1;

	int nr, nc;
	shark cur;
	while (!existSharkList.empty()) {
		cur = existSharkList.front();
		existSharkList.pop();

		if (board[cur.r][cur.c] == -1) continue;
		else if (board[cur.r][cur.c] != cur.sId) continue;
		board[cur.r][cur.c] = -1;

		int sp = cur.speed;
		while (sp > 0) {
			if (cur.dir == 0) {
				// up
				if (cur.r - sp >= 1) {
					cur.r -= sp;
					sp = 0;
				}
				else {
					cur.dir = ((cur.dir + 2) % 4);
					sp -= (cur.r - 1);
					cur.r = 1;
				}
			}
			else if (cur.dir == 1) {
				// right
				if (cur.c + sp <= C) {
					cur.c += sp;
					sp = 0;
				}
				else {
					cur.dir = ((cur.dir + 2) % 4);
					sp -= (C - cur.c);
					cur.c = C;
				}
			}
			else if (cur.dir == 2) {
				// down
				if (cur.r + sp <= R) {
					cur.r += sp;
					sp = 0;
				}
				else {
					cur.dir = ((cur.dir + 2) % 4);
					sp -= (R - cur.r);
					cur.r = R;
				}
			}
			else if (cur.dir == 3) {
				// left
				if (cur.c - sp >= 1) {
					cur.c -= sp;
					sp = 0;
				}
				else {
					cur.dir = ((cur.dir + 2) % 4);
					sp -= (cur.c - 1);
					cur.c = 1;
				}
			}
		}
		
		if (tempBoard[cur.r][cur.c] == -1) {
			tempBoard[cur.r][cur.c] = cur.sId;
			tempList.push(cur);
		}
		else if (tempBoard[cur.r][cur.c] > -1 && sharkList[tempBoard[cur.r][cur.c]].size < cur.size) {
			tempBoard[cur.r][cur.c] = cur.sId;
			tempList.push(cur);
		}

		sharkList[cur.sId].r = cur.r;
		sharkList[cur.sId].c = cur.c;
		sharkList[cur.sId].dir = cur.dir;
	}

	existSharkList = tempList;
	for (int i = 0; i <= R; i++)
		for (int j = 0; j <= C; j++)
			board[i][j] = tempBoard[i][j];
}

void init() {
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			board[i][j] = -1;
		}
	}

	while (!existSharkList.empty()) {
		existSharkList.pop();
	}
}

int changeDirection(int dir) {
	switch (dir)
	{
	case 1:
		return 0;
	case 2:
		return 2;
	case 3:
		return 1;
	case 4:
		return 3;
	default:
		break;
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	int r, c, s, d, z;

	cin >> R >> C >> M;
	init();

	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		sharkList.push_back({ i,r,c,s,changeDirection(d),z });
		board[r][c] = i;
	}

	for (int i = 0; i < M; i++)
		existSharkList.push(sharkList.at(i));

	int ret, answer = 0;
	while (king.second != C) {
		// 낚시왕 이동
		king.second += 1;

		// 상어 잡기
		ret = findNearShark();
		if (ret > -1) {
			board[sharkList[ret].r][sharkList[ret].c] = -1;
			answer += sharkList[ret].size;
		}
		// 상어 이동
		moveShark();
	}

	cout << answer;

	return 0;
}
