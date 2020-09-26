#include <cstdio>

template<typename T>
struct vector {
   T *arr;
   int idx, sze;
   vector() :idx(0), sze(4) { arr = new T[sze]; }
   ~vector() { if (arr) delete[] arr; }
   
   int size() { 
      return idx;
   }
   
   bool empty() { 
      return idx == 0;
   }
   
   T operator[](T const &index) { 
      return arr[index];
   }
   
   void push_back(T const &data) {
      if (idx == sze) {
         sze *= 2;
         T *tmp = new T[sze];
         for (int i = 0; i < idx; i++) tmp[i] = arr[i];
         delete[] arr;
         arr = tmp;
      }
      arr[idx++] = data;
   }
   
   T front() {
      return arr[0];
   }
   
   void pop_back() {
      idx--;
   }
};

int main() {
   vector<int> v;
   for (int i = 0; i < 1000; i++) v.push_back(i);
   for (int i = 0; i < v.size(); i++) printf("%d\n", v[i]);
   return 0;
}
