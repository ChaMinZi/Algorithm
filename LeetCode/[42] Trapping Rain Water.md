# [42. Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)

* #### Example 1

![image](https://user-images.githubusercontent.com/29828988/124425426-7b1f7900-dda3-11eb-8147-c4113875f4fc.png)

```
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
```

* #### Example 2

![image](https://user-images.githubusercontent.com/29828988/124425201-3267c000-dda3-11eb-8aa4-63d252f22f90.png)

```
Input: height = [4,2,0,3,2,5]
Output: 9
```

* #### Example 3

![image](https://user-images.githubusercontent.com/29828988/124425365-6511b880-dda3-11eb-8f1e-9caecfe83617.png)

```
Input: height = [2,0,2]
Output: 2
```

* #### Example 4

```
Input: height = []
Output: 0
```

-------------------------------------------

* ## C++

1. 최고 높이를 측정한다.
2. 왼쪽에서부터 최고 높이까지 빗물 용량을 구한다. ( 진행 방향 : ➡ )
3. 오른쪽에서부터 최고 높이까지 빗물 용량을 구한다. ( 진행 방향 : ⬅ )

```c++
class Solution {
public:
    int trap(vector<int>& height) {
        answer = 0;
        sidx = eidx = 0;

        if (height.size() == 0)
            return 0;

        int maxHeightIdx = 0, maxHeight = -1;

        for (int i = 0; i < height.size(); i++) {
            if (height[i] > maxHeight) {
                maxHeightIdx = i;
                maxHeight = height[i];
            }
        }

        svalue = -1;
        while (eidx <= maxHeightIdx) {
            if (height[eidx] > 0 && svalue == -1) {
                svalue = height[eidx];
                sidx = eidx;
            }
            else if (height[sidx] > 0 && height[eidx] >= height[sidx]) {
                svalue = height[sidx];
                for (int i = sidx; i < eidx; i++)
                    answer += (svalue - height[i]);

                sidx = eidx;
            }
            ++eidx;
        }

        sidx = eidx = height.size() - 1;
        svalue = -1;
        while (sidx >= maxHeightIdx) {
            if (height[sidx] > 0 && svalue == -1) {
                svalue = height[sidx];
                eidx = sidx;
            }
            else if (height[eidx] > 0 && height[sidx] >= height[eidx]) {
                svalue = height[eidx];
                for (int i = eidx; i > sidx; i--)
                    answer += (svalue - height[i]);
                eidx = sidx;
            }
            --sidx;
        }

        return answer;
    }

private:
    int answer, svalue;
    int sidx, eidx;
};
```

* ## C++ 더 나은 코드 O(n)

![KakaoTalk_20210706_114406935](https://user-images.githubusercontent.com/29828988/124539908-5554ab80-de59-11eb-8ce6-16a472bec2ee.jpg)

```c++
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0)
            return 0;

        volume = 0;
        left = 0;
        right = height.size() - 1;
        left_max = height[left];
        right_max = height[right];

        while (left < right) {
            left_max = max(height[left], left_max);
            right_max = max(height[right], right_max);

            // 더 높을 쪽을 향해 투 포인터 이동
            if (left_max <= right_max) {
                volume += (left_max - height[left]);
                ++left;
            }
            else {
                volume += (right_max - height[right]);
                --right;
            }
        }

        return volume;
    }

private:
    int volume;
    int left, right;
    int left_max, right_max;
};
```
