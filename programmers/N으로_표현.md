# [N으로 표현](https://programmers.co.kr/learn/courses/30/lessons/42895)

### 동적계획법(Dynamic Programming) 
#### - 불필요한 계산을 줄이고, 효율적으로 최적해를 찾아야만 풀리는 문제

`1 <= N <= 9`,  `1 <= number <= 32,000` 으로 값이 크지 않고 `최솟값이 8보다 크면 -1을 return 한다`는 조건 때문에 재귀로 풀 수 있을 것이라고 판단하였습니다.
N으로 구성된 숫자와 N/N으로 구성된 숫자들을 미리 구해놓으면 더 빠르게 처리할 수 있다고 판단하여 `numList`를 생성하였습니다.

* C++

```c++
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
	int num, cnt;
};

vector<Node> numList;
int res = 0xfffffff;

void solve(int target, int count, int val) {
	if (val == target) {
		if (res > count) {
			res = count;
		}
		return;
	}

	if (count > 8) {
		return;
	}

	for (int i = 0; i < numList.size(); i++) {
		if (val <= target) {
			solve(target, count + numList[i].cnt, val + numList[i].num);
			solve(target, count + numList[i].cnt, val * numList[i].num);
		}

		if (val >= numList[i].num)
			solve(target, count + numList[i].cnt, val - numList[i].num);
	
		if (val >= numList[i].num)
			solve(target, count + numList[i].cnt, val / numList[i].num);
	}
}

int solution(int N, int number) {
	int count = 0, temp = 0;
	temp = number;

	// size 측정
	while (temp != 0) {
		++count;
		temp /= 10;
	}

	// number list 구하기
	temp = 1;
	for (int i = 1; i <= count; i++) {
		numList.push_back({temp, i * 2});
		numList.push_back({ temp * N, i });
		temp = (temp * 10 + 1);
	}

	solve(number, 0, 0);

	return (res > 8)? -1 : res;
}
```
