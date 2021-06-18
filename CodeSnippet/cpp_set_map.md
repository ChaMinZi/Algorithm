# Map

* Map을 Value 기준으로 정렬하기

vector container에 복사해서 정렬해야 합니다.

```c++
vector<pair<string, int>> vec;
copy(list.begin(), list.end(), back_inserter<vector<pair<string, int>>>(vec)); // 벡터에 copy
sort(vec.begin(), vec.end(), comp);
```

# Set


