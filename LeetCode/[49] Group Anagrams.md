# [49. Group Anagrams](https://leetcode.com/problems/group-anagrams/)

## 📌 문제 설명

문자열을 애너그램으로 그룹화하세요! 반환값의 순서는 상관없습니다.

입력 문자열은 소문자로만 구성되어 있고 길이는 `0 <= strs[i].length <= 100`입니다.

### ❓ 애너그램(anagrams)이란? ❓

문자를 재배열하여 다른 뜻을 가진 단어로 바꾸는 것을 의미합니다. 

## Input Example
`
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
`

---------------------------------
## ✔ 풀이

애너그램을 판단하는 가장 쉬운 방법은 정렬하여 비교해보는 것입니다. 애너그램인 단어의 경우, 정렬을 하게되면 서로 같은 값을 가지게 되기 때문입니다.

1. 문자열을 정렬합니다.
2. unordered_map(hash table)에 넣어서 기록합니다.

* ### c++

```c++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> strs) {
        string str;
        unordered_map<string, vector<string>> map;
        vector<vector<string>> res;

        for (int i = 0; i < strs.size(); i++) {
            str = strs[i];
            sort(str.begin(), str.end());
        
            map[str].push_back(strs[i]);
        }

        for (auto iter: map) {
            res.push_back(iter.second);
        }

        return res;
    }
};
```

--------------------

* ### python

```python
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = collections.defaultdict(list)
        for word in strs:
            # 정렬하여 딕셔너리에 추가
            anagrams[''.join(sorted(word))].append(word)
    
        return list(anagrams.values())
```
