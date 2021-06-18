# C++ string과 관련된 snippet


* ## split

`#include<sstream>`를 추가해줘야 합니다.

### 1. istringstream과 getline을 이용하는 방법
```c++
    vector<string> splite(string record) {
        vector<string> temp;
        
        istringstream ss(record);
        string stringBuffer;
        while (getline(ss, stringBuffer, ' ')) {
            temp.push_back(stringBuffer);
        }
        return temp;
    }
```

### 2. find와 substr을 이용하는 방법

순차적으로 구분문자를 바꿀 수 있으므로 구분 문자가 두 개 이상일 때 유용하게 사용할 수 있다.

```c++
vector<string> splite(string in) {
    vector<string> ret;

    int previous = 0, current;
    current = in.find(',');

    //find 함수는 해당 위치부터 문자열을 찾지 못할 경우 npos를 반환한다.
    while (current != string::npos) {
        // 첫 인자의 위치부터 두번째 인자 길이만큼 substring을 반환
        string substring = in.substr(previous, current - previous);
        ret.push_back(substring);
        
        previous = current + 1;

        //previous 부터 ,이 나오는 위치를 찾는다.
        current = in.find(',', previous);
    }
    //마지막 문자열 출력
    ret.push_back(in.substr(previous, current - previous));

    return ret;
}
```

</br>

* ## string ↔ char

* `string`을 `char*` 로 바꾸기
```c++
char* cStr = (char*)cppStr.c_str(); // c_str()은 const char* 로 반환합니다.
```

* `string`을 `ch[]`로 바꾸기
```c++
char ch[10];
strcpy(ch, str.c_str());
or
strcpy_s(ch, str.c_str());
```

</br>

* ## reverse

`#include <algorithm>` 헤더를 추가해줘야 합니다.

```c++
reverse(str.begin(), str.end());
```

</br>

* ## string을 대/소문자로 변환

`#include <algorithm>` 헤더를 추가해줘야 합니다.

```c++
string s = "abDGSsdFDSafds";
transform(s.begin(), s.end(), s.begin(), ::tolower);	// 소문자 변환
transform(s.begin(), s.end(), s.begin(), ::toupper);	// 대문자 변환
```
