# [플로이드 와샬](https://blog.naver.com/ndb796/221234427842)

**다익스트라(Dijkstra) 알고리즘**은 하나의 정점에서 출발했을 때 다른 모든 정점으로의 최단 경로를 구하는 알고리즘이라면,

**플로이드 와샬(Floyd Warshall) 알고리즘**은 `모든 정점`에서 `모든 정점`으로의 최단 경로를 구하는 알고리즘입니다.  
그래프에서 `X->Y로 가는 최소 비용`과 `X->(기준 노드)로 가는 비용 + Y->(기준 노드)로 가는 비용`을 비료하여 최소 비용을 갱신하는 방식으로 동작합니다.

## 📌 [백준 - 플로이드 문제 풀이 중 일부](https://www.acmicpc.net/problem/11404)

단방향 그래프에서 플로이드 와샬을 사용하여 최거 거리를 구하는 문제로 플로이드 와샬의 기본적인 코드만으로 풀이할 수 있는 문제입니다.

```c++
    ...
    for (int p = 1; p <= N; p++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (board[i][p] && board[p][j] && (board[i][j] == 0 ||
                    board[i][j] > board[i][p] + board[p][j]))
                    board[i][j] = board[i][p] + board[p][j];
            }
        }
    }
    ...
```