#include <cstdio>

using namespace std;

const int MAXN = 1e5 + 6;

template<typename T>
void swap(T *a, T *b) {
   T tmp = *a;
   *a = *b;
   *b = tmp;
}

template<typename T>
struct priority_queue {
   T arr[MAXN];
   int idx;
   priority_queue() :idx (0) {}
   
   bool empty() { return idx == 0; }
   int size() { return idx; }
   T top() { return arr[0]; }
   
   void push(T const &data) {
      arr[idx++] = data;      
      int curr = idx - 1;
      while (1) {
         if (curr == 0) break;
         int par = (curr - 1) / 2;
         if (arr[par] > arr[curr]) swap(&arr[par], &arr[curr]);
         curr = par;
      }
   }
   
   void pop() {
      arr[0] = arr[--idx];
      int curr = 0, next;
      while (curr * 2 + 1 < idx) {
         next = curr;
         if (arr[next] > arr[curr * 2 + 1]) next = curr * 2 + 1;
         if (curr * 2 + 2 < idx && arr[next] > arr[curr * 2 + 2]) next = curr * 2 + 2;
         if (next == curr) break;
         swap(&arr[curr], &arr[next]);
         curr = next;
      }
   }

};

int main() {
   priority_queue<int> pq;
   int n;
   scanf("%d", &n);
   for (int i = 0,d ; i < n; i++) {
      scanf("%d", &d);
      if (d == 0) {
         if (pq.empty()) printf("0\n");
         else printf("%d\n", pq.top()), pq.pop();
      }
      else pq.push(d);
   }
   return 0;
}
