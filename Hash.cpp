#include <iostream>
#define HASH_SIZE 100000 // 소수로 설정해주는게 더 나음

using namespace std;

int hash[HASH_SIZE];
int prime[3] = {31, 997, 10007};

int getHashKey(char str[]) {
  unsigned int mux = 1, re = 0;
  for (int i=0; str[i] != 0; i++) {
    mux *= prime[re%3];
    re += (str[i] * mux);
  }
  return re % HASH_SIZE: // HASH_SIZE를 (2^N-1)로 설정하면 & 연산으로 해도 됨
}
