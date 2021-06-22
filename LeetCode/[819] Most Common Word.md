# [819. Most Common Word](https://leetcode.com/problems/most-common-word/)

* ## 문제 설명
`paragraph string`은 `' '`이나 `"!?',;."`와 함께 구성되어 있습니다. 여기서 단어만 골라내어 banned word 리스트에 없는 단어 중 가장 빈번하게 등장하는 단어를 출력하는 문제입니다.

* ## Example

```
Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
Output: "ball"
Explanation: 
"hit"는 string 내부에 3번 등장하지만 banned word이기 때문에 제외합니다. 
banned word가 아니면서 가장 많이 등장하는 단어가 "ball" 이므로 이를 반환합니다.
( 이때, 단어의 대소문자를 구분하지 않습니다. )
```

-----------------------

* ### C++

구분자를 확인하면서로 바로 단어를 분리하는 방법으로 36ms 정도의 시간이 걸렸습니다.

```c++
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <sstream>

using namespace std;

bool comp(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

class Solution {
public:
    struct myOreder {
        bool operator() (const int& a, const int& b) const {
            return a > b;
        }
    };

    map <string, int> list;

    int findChar(string paragraph, int idx) {
        string ch = "";
        int ret, temp;

        ret = INT_MAX;

        temp = paragraph.find(" ", idx);
        if (temp != string::npos && temp < ret) {
            ch = " ";
            ret = temp;
        }
        temp = paragraph.find("!", idx);
        if (temp != string::npos && temp < ret) {
            ch = "!";
            ret = temp;
        }
        temp = paragraph.find("?", idx);
        if (temp != string::npos && temp < ret) {
            ch = "?";
            ret = temp;
        }
        temp = paragraph.find("'", idx);
        if (temp != string::npos && temp < ret) {
            ch = "'";
            ret = temp;
        }
        temp = paragraph.find(",", idx);
        if (temp != string::npos && temp < ret) {
            ch = ",";
            ret = temp;
        }
        temp = paragraph.find(";", idx);
        if (temp != string::npos && temp < ret) {
            ch = ";";
            ret = temp;
        }
        temp = paragraph.find(".", idx);
        if (temp != string::npos && temp < ret) {
            ch = ".";
            ret = temp;
        }

        if (ch == "")
            return string::npos;

        return ret;
    }

    bool findBanned(vector<string> banned, string st) {
        for (int i = 0; i < banned.size(); i++) {
            if (banned[i].compare(st) == 0)
                return false;
        }
        return true;
    }

    void insertMap(string substring, vector<string> banned) {
        transform(substring.begin(), substring.end(), substring.begin(), ::tolower);
        if (substring != "" && findBanned(banned, substring))
            list[substring] += 1;
    }


    string mostCommonWord(string paragraph, vector<string> banned) {

        // split
        int previous = 0, current;
        current = findChar(paragraph, previous);

        //find 함수는 해당 위치부터 문자열을 찾지 못할 경우 npos를 반환한다.
        while (current != string::npos) {
            // 첫 인자의 위치부터 두번째 인자 길이만큼 substring을 반환
            string substring = paragraph.substr(previous, current - previous);
            insertMap(substring, banned);

            previous = current + 1;

            current = findChar(paragraph, previous);
        }
        //마지막 문자열 출력
        insertMap(paragraph.substr(previous, current - previous), banned);

        // 정렬
        vector<pair<string, int>> vec;
        copy(list.begin(), list.end(), back_inserter<vector<pair<string, int>>>(vec));
        sort(vec.begin(), vec.end(), comp);

        return vec[0].first;
    }
};
```

* ### C++ 시간 복잡도를 더 줄인 코드

    1. 단어를 만들면서 hash에 개수와 함께 저장합니다.
    2. for문으로 가장 빈번하게 등장하는 단어를 기록합니다. 이때, banned 단어가 아닌 경우만 빈도를 체크합니다.

```c++
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> store;
        string str = "";
        int freq = INT_MIN;
        string res;

        for (int i = 0; i < paragraph.length(); ++i) {
            if (paragraph[i] >= 'A' && paragraph[i] <= 'Z')
                str += (paragraph[i] - 'A' + 'a');
            else if (paragraph[i] >= 'a' && paragraph[i] <= 'z')
                str += paragraph[i];
            else {
                store[str]++;
                str = "";
            }

        }

        if (str.size() > 0)
            store[str]++;

        for (auto i : store) {
            cout << i.first << " " << i.second << endl;
            if (i.second > freq 
                && find(banned.begin(), banned.end(), i.first) == banned.end()
                && i.first.size() > 0) {
                freq = i.second;
                res = i.first;
            }
        }
        return res;
    }
};
```

-----------------------

* ### python

    1. 정규표현식을 이용하여 모든 구분자를 공백으로 치환합니다.
    2. Counter 모듈을 이용하여 개수를 처리합니다.
    3. most_common 을 이용하여 가장 빈번하게 등장하는 값을 추출<br>( ex. most_common(1) : [('ball', 2)] )

```python
def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
    # 정규식으로 문자 이외의 모든 표현을 공백으로 치환
    words = [word for word in re.sub(r'[^\w]', ' ', paragraph)
        .lower().split()
        if word not in banned]

    counts = collections.Counter[words]
    # 가장 흔하게 등장하는 단어의 첫 번째 인덱스 리턴
    return counts.most_common(1)[0][0]
```
