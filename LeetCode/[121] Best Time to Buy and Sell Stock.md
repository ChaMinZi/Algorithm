# [121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

가장 큰 이득을 얻었을 때의 값을 계산하는 문제

* ### Examples

![image](https://user-images.githubusercontent.com/29828988/125226233-a0643800-e30b-11eb-95f9-3c91ce3d7623.png)

---------------------------------------------

* ### C++ - 184ms
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minid, maxid, answer = 0;

        minid = 0;
        maxid = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[minid] > prices[i]) {
                minid = i;
                maxid = i;
            }
            else if (prices[maxid] < prices[i]) {
                if (i > minid) {
                    if (answer < (prices[i] - prices[minid]))
                        answer = (prices[i] - prices[minid]);
                    maxid = i;
                }
            }
        }

        return answer;
    }
};
```

* ### C++ - 152ms
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minP = INT_MAX, res = 0;

        for (int idx = 0; idx < prices.size(); idx++) {
            if (prices[idx] < minP) {
                minP = prices[idx];
            }
            if (prices[idx] - minP > res) {
                res = prices[idx] - minP;
            }
        }

        return res;
    }
};
```
