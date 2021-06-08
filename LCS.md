# LCS 알고리즘

> [그림으로 알아보는 LCS 알고리즘](https://velog.io/@emplam27/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EA%B7%B8%EB%A6%BC%EC%9C%BC%EB%A1%9C-%EC%95%8C%EC%95%84%EB%B3%B4%EB%8A%94-LCS-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Longest-Common-Substring%EC%99%80-Longest-Common-Subsequence) 을 참고하였습니다.  
> 해당 블로그에 더 자세한 내용이 게시되어 있습니다.

LCS 알고리즘이라고 하면 보통 **Longest Common Subsequence(최장 공통 부분수열)** 을 의미하지만, **Longest Common Substring(최장 공통 문자열)** 을 의미하기도 합니다.

![image](https://user-images.githubusercontent.com/29828988/121180505-e573f500-c89b-11eb-8a9e-c31269f437bc.png)

위의 그림에서 알 수 있듯이 **Longest Common Subsequence(최장 공통 부분수열)**은 **BCDF**도 될 수 있고, **BCDE**도 될 수 있습니다. 
부분수열이라는 단어와 같이 두 문자열에 모두 존재하는 글자를 이어붙여 가장 긴 부분 문자열을 찾아내면 됩니다.
반면에 **Longest Common Substring(최장 공통 문자열)** 의 경우 이어져 있는 문자열만 가능합니다. 

---------------------------------------------------------
</br>

# 1. Longest Common Substring (최장 공통 문자열)

최장 공통 문자열은 두 개의 문자열 내부에서 연속되어야 하기 때문에, 직전 문자의 동일 여부를 바탕으로 현재 위치에서 연속된 길이를 계산할 수 있습니다.

아래의 과정을 통해서 최장 공통 문자열의 길이를 구할 수 있습니다.

![image](https://user-images.githubusercontent.com/29828988/121182244-da21c900-c89d-11eb-95e0-2bfa84ab2a3c.png)

```
  1. 행과 열의 크기가 N인 LCS 2차원 배열을 생성하고 LCS 배열 값을 0으로 초기화해줍니다.
  2. (1,1)부터 시작해서 행의 문자와 열의 문자를 비교합니다.
  3. 현재 위치를 기준으로 두 문자가 다르다면 LCS[j][i] = 0
  4. 현재 위치를 기준으로 두 문자가 같다면 LCS[j][i] = LCS[j-1][i-1] + 1
  5. 3번과 4번의 과정을 짧은 문자열의 길이까지 반복합니다.
```

</br>

# 2. Longest Common Subsequence (최장 공통 부분수열)

**최장 공통 문자열**을 구하는 과정과 유사하지만 비교하는 두 문자가 다를 때 처리하는 로직이 조금 다릅니다.

![image](https://user-images.githubusercontent.com/29828988/121183971-94660000-c89f-11eb-8f96-4613e4dc8b48.png)

```
  1. 행과 열의 크기가 N인 LCS 2차워 배열을 생성하고 r=0이거나 c=0인 LCS 배열의 값을 0으로 초기화해줍니다.
  2. (1,1)부터 시작해서 행의 문자와 열의 문자를 비교합니다.
  3. 현재 위치를 기준으로 두 문자가 다르다면 LCS[j][i] = max(LCS[j-1][i], LCS[j][i-1])
  4. 현재 위치를 기준으로 두 문자가 같다면 LCS[r][c] = LCS{j-1][i-1] + 1
  5. 3번과 4번 과정을 짧은 문자열의 길이까지 반복합니다.
```

위의 과정에서 최장 공통 부분수열의 길이뿐만 아니라 결과 값도 구하기 위해서는 마지막 값에서부터 역행해서 찾아가면 됩니다.

![image](https://user-images.githubusercontent.com/29828988/121184163-c6776200-c89f-11eb-8ab7-7c5bae62f14d.png)

```
  1. LCS 배열의 가장 마지막 위치에서 시작합니다.
  2. 현재 위치 (j, i)의 값과 (j-1, i)와 (j, i-1)의 값을 비교합니다.
     2-1) 같은 값이 있는 경우, 같은 값이 있는 위치로 이동합니다. 만약 위쪽과 왼쪽 모두 값이 같은 경우, 위쪽 방향으로 이동합니다.
     2-2) 같은 값이 없는 경우, result 배열에 해당 문자를 넣고 LCS[j-1][i-1]로 이동합니다.
  3. 2번 과정을 반복 진행하다가 LCS[j][i] = 0인 위치로 이동하면 종료합니다.
  4. result 배열의 역순이 최장 공통 부분수열 문자열입니다.
```
