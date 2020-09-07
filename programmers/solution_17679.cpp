#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#define SZ 32

using namespace std;

int dy[] = { 1, 1, 0 }, dx[] = { 0,1,1 };
vector<string> originMap;

int chkRemove(int m, int n) {
    int chkMap[SZ][SZ] = { 0, };
    int cnt = 0;

    for (int r = 0; r < m-1; r++) {
        for (int c = 0; c < n-1; c++) {
            char compCh = originMap[r][c];
            if (compCh == 'z')
                continue;

            if (compCh == originMap[r + 1][c] && compCh == originMap[r][c + 1] && compCh == originMap[r + 1][c + 1]) {
                chkMap[r][c] = 1;
                chkMap[r + 1][c] = 1;
                chkMap[r][c + 1] = 1;
                chkMap[r + 1][c + 1] = 1;
            }
        }
    }

    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            if (chkMap[r][c] == 1) {
                cnt++;
                originMap[r][c] = 'z';
            }
        }
    }

    queue<char> que;
    for (int c = 0; c < n; c++) {
        while (!que.empty())
            que.pop();

        for (int r = m-1; r >= 0; r--) {
            if (originMap[r][c] != 'z') {
                que.push(originMap[r][c]);
            }
        }

        while (que.size() < m)
            que.push('z');

        for (int r = m - 1; r >= 0; r--) {
            originMap[r][c] = que.front();
            que.pop();
        }
    }

    return cnt;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    originMap = board;

    int ret = 1;
    while (ret != 0) {
        ret = chkRemove(m, n);
        answer += ret;
    }

    return answer;
}
