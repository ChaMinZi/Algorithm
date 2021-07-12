# [238. Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)

* ### 문제 설명

배열을 입력받아 `output[i]`가 자신을 제외한 나머지 모든 요소의 곱셈 결과가 되도록 출력하는 문제

-----------------------------------------------------

* ### C++

![image](https://user-images.githubusercontent.com/29828988/125234072-dfe65080-e31a-11eb-9811-473d0f057385.png)

```c++
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,1);
        vector<int>suffix(n,1);
        vector<int>prefix(n,1);

        for(int i = 1 ; i < n; i++)
            prefix[i] = prefix[i-1]*nums[i-1];
        for(int i = n-2 ; i >= 0; i--)
            suffix[i] = suffix[i+1]*nums[i+1];
         for(int i = 0 ; i < n; i++)
            ans[i] = prefix[i]*suffix[i];
        return ans;
    }
};
```
