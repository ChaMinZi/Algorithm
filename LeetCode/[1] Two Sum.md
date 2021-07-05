# [1. Two Sum](https://leetcode.com/problems/two-sum/)

배열에서 덧셈하여 타겟을 만들 수 있는 두 수의 인덱스를 리턴하는 문제

---------------------------

* ### C++ - 브루트 포스 
 
O(n^2)의 시간 복잡도를 가지는 방법

```c++
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int select, other, size;
		vector<int> ans;

		size = nums.size();
		for (int i = 0; i < size; i++) {
			select = nums[i];
			for (int j = i+1; j < size; j++) {
				if (nums[j] == (target - select)) {
					ans.push_back(i);
					ans.push_back(j);
				}
			}
		}

		return ans;
	}
};
```

* ### C++ - Map 이용

타켓에서 첫 번째 수를 뺀 값을 Map(hash)에 저장하면서 찾는 방법

```c++
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> m;
		vector<int> res;

		for (int i = 0; i < nums.size(); i++) {
			auto p = m.find(target - nums[i]);
			if (p != m.end()) {
				res.insert(res.begin(), { i, p->second });
				return res;
			}
			m[nums[i]] = i;
		}
		return res;
	}
};
```
