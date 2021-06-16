# [ 125.  Valid Palindrome ](https://leetcode.com/problems/valid-palindrome/)

입력받는 `string`의 길이는 `1 <= s.length <= 2 * 105`로 오직 아스키코드로만 이루어져 있습니다.

입력받은 s 중에서 영숫자만 고려하여 해당 문자열이 팰린드롬인지 판단하는 문제입니다.

-----------------------------------------
* c++

```c++
class Solution {
public:
    bool isPalindrome(string s) {
        int sz = s.size();
        string newStr;

        for (int i = 0; i < sz; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                newStr += s[i];
            }
            else if (s[i] >= 'A' && s[i] <= 'Z') {
                newStr += (s[i] + ('a' - 'A'));
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                newStr += s[i];
            }
        }

        sz = newStr.size();
        for (int i = 0; i < sz / 2; i++) {
            if (newStr[i] != newStr[sz - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};
```
