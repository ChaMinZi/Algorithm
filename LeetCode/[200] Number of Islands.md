# [200. Number of Islands](https://leetcode.com/problems/number-of-islands/)

```c++
class Solution {
public:
    int chk = 0;
    int dr[4] = { -1,0,1,0 }, dc[4] = { 0,1,0,-1 };
    int m, n;

    bool isPossi(int r, int c) {
        return (r >= 0 && c >= 0 && r < m && c < n);
    }

    void getRegion(int sr, int sc, vector<vector<char>>& gird) {
        queue<pair<int, int>> que;

        int nr, nc;
        que.push(make_pair(sr, sc));
        gird[sr][sc] = '2';

        while (!que.empty()) {
            pair<int, int> cur = que.front();
            que.pop();

            for (int dir = 0; dir < 4; dir++) {
                nr = cur.first + dr[dir];
                nc = cur.second + dc[dir];

                if (!isPossi(nr, nc)) continue;
                if (gird[nr][nc] == '0' || gird[nr][nc] == '2') continue;

                gird[nr][nc] = '2';
                que.push(make_pair(nr, nc));
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == '1') {
                    ++chk;
                    getRegion(r, c, grid);
                }
            }
        }

        return chk;
    }
};
```
