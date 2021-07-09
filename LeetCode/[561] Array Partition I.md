# [561. Array Partition I](https://leetcode.com/problems/array-partition-i/)

n 개의 페이를 만들어서 min(pair1, pair2)의 합으로 만들 수 있는 가장 큰 수를 만드는 문제

### 📌 풀이 설명

페어의 min을 합산했을 때 최대를 만드는 것은 결국 min()이 될 수 있는 한 커야 한다는 뜻입니다.  
오름차순 정렬 후 인접 요소를 페어로 만들면 가장 큰 a1, a2가 페어를 만들게 되고 이 페어들의 합이 곧 만들 수 있는 최대 합이 됩니다.

------------------------------------------
* ### C++

페어를 만들 때, 정렬 한 후 짝수 번째 값은 항상 작은 값이므로 굳이 `min()`을 사용하지 않아도 됩니다.

```c++
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int sum = 0;
        for (int i=0; i<nums.size(); i+=2) {
            sum += nums[i];
        }
        
        return sum;
    }
};
```
