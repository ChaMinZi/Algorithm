# [5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/) 

주어진 string에서 가장 긴 팰린드롬 subString을 구하는 문제입니다.

* ### Example

```
Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
```

```
Input: s = "cbbbbbbbbd"
Output: "bbbbbbbb"
```

--------------------------------------------

## 💡 투 포인터 이용

* ### C++ ( 60ms )

![image](https://user-images.githubusercontent.com/29828988/123233939-77733300-d515-11eb-94e3-88dc3a4c79eb.png)

기준점으로 두고 양쪽으로 포인터를 확장해가면서 팰린드롬인지 판단하는 방식으로 구현하였습니다. 이때, 문자열의 길이가 짝수인 경우와 홀수인 경우로 나누어서 구합니다. 

```c++
class Solution {
public:
	string getPalindrome(int left, int right, int sz, string str) {	
		while (left > 0 && right + 1 < sz) {
			if (str[left - 1] == str[right + 1]) {
				left--;
				right++;
			}
			else
				break;
		}
		return str.substr(left, right - left + 1);
	}

    string longestPalindrome(string str) {
		int s, e, diff;
		string res = "", temp1, temp2;

		for (int piv = 0; piv < str.size(); piv++) {
			temp1 = getPalindrome(piv, piv, str.size(), str);
			res = (temp1.size() > res.size()) ? temp1 : res;

			if (str[piv] == str[piv + 1]) {
				temp2 = getPalindrome(piv, piv + 1, str.size(), str);
				res = (temp2.size() > res.size()) ? temp2 : res;
			}
		}
		return res;
	}
};
```

* ### 좀 더 나은 시간복잡도를 가지는 방법 ( 0 ms )

```c++
class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.size();
        int max_s = 0, max_l = 0;
        for (int i = 0; i < sz;) {
            int start = i, end = i;
            while (end + 1 < sz && s[end] == s[end + 1]) end++;
            i = end + 1;
            while (start - 1 >= 0 && end + 1 < sz && s[start - 1] == s[end + 1]) {
                start--;
                end++;
            }
            if (end - start + 1 > max_l) {
                max_l = end - start + 1;
                max_s = start;
            }
        }
        return s.substr(max_s, max_l);
    }
};
```
