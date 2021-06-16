# [ 344. Reverse String ](https://leetcode.com/problems/reverse-string/)

문자열을 뒤집어서 출력하는 문제입니다. 이때, 문자열의 길이는 `1 <= s.length <= 10^5`입니다. 

--------------------------

* c++

`reverse()` 함수는 `<algorithm>` 헤더에 포함되어 있습니다.

```c++
class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};
```
