# [937. Reorder Data in Log Files](https://leetcode.com/problems/reorder-data-in-log-files/)

### [ 문제 설명 ]
    1. letter-logs가 모든 digit-logs보다 앞에 와야합니다.
    2. letter-logs는 내용을 기준으로 사전순 정렬합니다. 만약 내용이 같다면 식별자를 기준으로 사전순 정렬합니다. 
    3. digit-logs는 정렬하지 않고 순서를 유지합니다.

### [ Example ]
```
Input: logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
```
---------------------------

* ### c++

```c++
bool comp(string& a, string& b) {
    string aa = a.substr(a.find(' '));  // aa: act car, a : g1 act car
    string bb = b.substr(b.find(' '));

    return aa == bb ? a < b : aa < bb;
}

class Solution {
public:
    vector<string> reorderLogFiles(vector<string> logs) {
        vector<string> letters;
        vector<string> digits;
	
	// 1. 타입 확인
        for (string& str : logs) {
            int i = 0;
            while (i < str.size() && str[i++] != ' ');
            if (isalpha(str[i]))
                letters.push_back(str);
            else
                digits.push_back(str);
        }
	
	// 2. 먼저 문자열 내용을 기준으로 정렬 -> 문자열이 동일하면 식별자 기준으로 정렬
        sort(letters.begin(), letters.end(), comp);
	
	// 3. 합치기 ( letters.end() 뒤에 digits를 합쳐준다. )
        letters.insert(letters.end(), digits.begin(), digits.end());
        return letters;
    }
};

int main() {
    vector<string> ret = Solution().reorderLogFiles(
        { "a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo" }
    );

    return 0;
}
```

</br>

* ### `Class` 내부에 `comp`를 선언하는 방법

  > [모두의 코드 - 람다(lambda) 함수 ](https://modoocode.com/196) 참고

```c++
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        auto comp = [](string &a, string &b) {
            string aa = a.substr(a.find(' '));
            string bb = b.substr(b.find(' '));
            
            return aa == bb ? a < b : aa < bb;
        };
        
        vector<string> letters;
        vector<string> digits;
        for (string &str: logs) {
            int i = 0;
            while (i < str.size() && str[i++] != ' ');
            if (isalpha(str[i]))
                letters.push_back(str);
            else
                digits.push_back(str);
        }
        
        sort(letters.begin(), letters.end(), comp);
        
        letters.insert(letters.end(), digits.begin(), digits.end());
        return letters;
    }
};
```

---------

* Python

```python
from typing import List

class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        letters, digits = [], []
        for log in logs:
            if log.split()[1].isdigit():
                digits.append(log)
            else:
                letters.append(log)

        # 두 개의 키를 람다 표현식으로 정렬
        letters.sort(key=lambda x: (x.split()[1:], x.split()[0]))
        return letters + digits
```
