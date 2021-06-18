# [819. Most Common Word](https://leetcode.com/problems/most-common-word/)

* ## 문제 설명
`paragraph string`은 ' '이나 "!?',;."와 함께 구성되어 있습니다. 여기서 단어만 골라내어 banned word 리스트에 없는 단어 중 가장 빈번하게 등장하는 단어를 출력하는 문제입니다.

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
