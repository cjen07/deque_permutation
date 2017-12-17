#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

list<int> A;
vector<bool> B;
vector<list<int>::iterator> I;
int n = 8;
int a[8] = {3, 1, 6, 4, 8, 5, 2, 7};
int k, base, mx;
list<int>::iterator it;
list<int>::iterator it2;

void F101(int x, int y);
void F102(int x, int y);
void F10(int a, int b, int c, int d);
void F01(int p, int x, bool d);
bool F0(int p);
bool F1(int p);
int F20(int p);
bool F2(int p);
bool F();

void show(){
  cout << "list: ";
  for(list<int>::iterator i = A.begin(); i != A.end(); i++)
    cout << *i << " ";
  cout << endl;
}

void F101(int x, int y){
  cout << "F101" << endl;
  show();
  int z = -1, w = -1;
  for(int i = x; i <= y; i++){
    if(B[i]){
      B[i] = 0;
    }
    else{
      z = i;
      break;
    }
  }
  if(z != -1){
    for(int i = y; x <= i; i--){
      if(B[i]){
        B[i] = 0;
      }
      else{
        w = i;
        break;
      }
    }
    cout << "z w: " << z << " " << w << " " << endl;
    if(z == w){
      A.push_back(z);
    }
    else{
      cout << "z w: " << z << " " << w << " " << endl;
      base = z;
      cout << "base: " << base << endl;
      A.push_back(w);
      it = --A.end();
      show();
    }
  }
  // else if(z != -1){
  //   for(int i = z; i <= y; i++){
  //     if(B[i]){
  //       B[i] = 0;
  //     }
  //     else{
  //       A.push_back(i);
  //     }
  //   }
  // }
}

void F102(int x, int y){
  cout << "F102" << endl;
  show();
  for(int i = x; i <= y; i++){
    if(B[i]){
      B[i] = 0;
    }
    else{
      A.push_back(i);
    }
  }
}

void F10(int a, int b, int c, int d){
  cout << "F10" << endl;
  cout << "args" << a << " " << b << " " << c << " " << d << endl;
  show();
  F101(a, b);
  F102(c, d);
}

void F01(int p, int x, bool d){
  cout << "F01" << endl;
  show();
  int i;
  if(p == base){
    it = A.end();
    if(d){
      A.pop_front();
      for(i = x; i >= base + 1; i--){
        if(B[i]){
          B[i] = 0;
        }
        else{
          A.push_front(i);
        }
      }
    }
    else{
      A.pop_back();
      for(i = x; i >= base + 1; i--){
        if(B[i]){
          B[i] = 0;
        }
        else{
          A.push_back(i);
        }
      }
    }
  }
  else if(p == x){
    if(base == x - 1){
      (*it)--;
      it = A.end();
    }
    else{
      for(i = x - 1; i > base; i--){
        if(B[i]){
          B[i] = 0;
        }
        else{
          break;
        }
      }
      (*it) = i;
      if(i == base){
        it = A.end();
      }
    }    
  }
  else{
    for(i = p - 1; i >= base; i--){
      if(B[i]) B[i] = 0;
      else break;
    }
    (*it) = i;
    if(i == base) it = A.end();
    if(d){
      it2 = ++A.begin();
      for(i = p + 1; i <= x; i++){
        if(B[i]) B[i] = 0;
        else{
          A.insert(it2, i);
        }
      }
    }
    else{
      it2 = --A.end();
      for(i = p + 1; i <= x; i++){
        if(B[i]) B[i] = 0;
        else{
          A.insert(it2, i);
        }
      }
    }
  }
  cout << "AF01" << endl;
  show();
}

bool F0(int p){
  cout << "F0" << endl;
  cout << "p: " << p << endl;
  show();
  int f, b;
  f = A.front();
  b = A.back();
  cout << "f b " << f << " " << b << endl;
  cout << ((it != A.end()) ? "Yes" : "No") << endl;
  cout << "base: " << base << endl;
  if(it != A.end() && *it == f && base <= p && p <= f){
    F01(p, f, 1);
    return F();
  }
  else{
    if(f == p){
      A.pop_front();
      return F();
    }
  }
  if(f != b){
    if(it != A.end() && *it == b && base <= p && p <= b){
      F01(p, b, 0);
      return F();
    }
    else{
      if(b == p){
        A.pop_back();
        return F();
      }
    }
  }
  return 0;
}

bool F1(int p){
  cout << "F1" << endl;
  show();
  int q;
  while(k < n){
    q = a[k++];
    if(q > p){
      B[p] = 1;
      p = q;
    }
    else{
      cout << "k is " << k << endl;
      F10(mx+1, q-1, q+1, p-1);
      mx = p;
      return F();
    }
  }
  return 1;
}

int F20(int p){
  cout << "F20" << endl;
  show();
  int f, b;
  f = A.front();
  b = A.back();
  if(it != A.end() && *it == f && base <= p && p <= f){
    F01(p, f, 1);
    return 1;
  }
  else{
    if(f == p){
      A.pop_front();
      return 1;
    }
  }
  if(f != b){
    if(it != A.end() && *it == b && base <= p && p <= b){
      F01(p, b, 0);
      return 0;
    }
    else{
      if(b == p){
        A.pop_back();
        return 0;
      }
    }
  }
  return -1;
}

bool F2(int p){
  cout << "F2" << endl;
  show();
  vector<int> C;
  B[p] = 1;
  C.push_back(p);
  while(k < n){
    p = a[k++];
    if(p < mx){
      break;
    }
    else{
      B[p] = 1;
      C.push_back(p);
    }
  }
  int z = F20(p);
  cout << "z: " << z << endl;
  cout << "here 1" << endl;
  if(z == 0){
    A.push_back(n+1);
    it2 = --A.end();
    for(int i = 0; i < C.size(); i++){
      cout << "here 3" << endl;
      if(C[i] > mx){
        cout << "here 4" << endl;
        for(int j = mx + 1; j < C[i]; j++){
          if(B[j]){
            A.push_back(-j);
            A.push_front(-j);
            I[j] = A.begin();
          }
          else{
            A.push_front(j);
          }
        }
        mx = C[i];
        B[C[i]] = 0;
      }
      else{
        cout << "here 5" << endl;
        int x;
        bool y = 0;
        x = A.back();
        cout << "x: " << x << endl;
        cout << "c i: " << C[i] << endl;
        show();
        cout << "here 9" << endl;
        while(x + C[i] <= 0){
          A.pop_back();
          cout << "here 10" << endl;
          if(x + C[i] == 0){
            cout << "here 8" << endl;
            show();
            cout << *(I[C[i]]) << endl;
            // it2 = I[C[i]];
            // it2++;
            // cout << *it2 << endl;
            A.erase(I[C[i]]);
            show();
            cout << "here 7" << endl;
            y = 1;
            break;
          }
          x = A.back();
        }
        cout << "here 6" << endl;
        if(y) continue;
        x = A.front();
        if(x < 0 && x + C[i] == 0){
          A.pop_front();
          I[C[i]] = A.end();
        }
        else{
          return 0;
        }
      }
    }
    cout << "here 2" << endl;
    A.erase(it2);
    return F();
  }
  else if(z == 1){
    A.push_front(n+1);
    it2 = A.begin();
    for(int i = 0; i < C.size(); i++){
      if(C[i] > mx){
        for(int j = mx + 1; j < C[i]; j++){
          if(B[j]){
            A.push_back(-j);
            A.push_front(-j);
            I[j] = --A.end();
          }
          else{
            A.push_back(j);
          }
        }
        mx = C[i];
        B[C[i]] = 0;
      }
      else{
        int x;
        bool y = 0;
        x = A.front();
        while(x + C[i] <= 0){
          A.pop_front();
          if(x + C[i] == 0){
            A.erase(I[C[i]]);
            y = 1;
            break;
          }
          x = A.front();
        }
        if(y) continue;
        x = A.back();
        if(x < 0 && x + C[i] == 0){
          A.pop_back();
          I[C[i]] = A.end();
        }
        else{
          return 0;
        }
      }
    }
    A.erase(it2);
    return F();
  }
  return 0;
}

bool F(){
  cout << "F" << endl;
  show();
  int p;
  if(k < n){
    p = a[k++];
    if(p < mx){
      return F0(p);
    }
    else{
      if(A.empty()){
        return F1(p);
      }
      else{
        return F2(p);
      }
    }
  }
  else{
    return 1;
  }
}

int main(){
  k = 0;
  mx = 0;
  it = A.end();
  for(int i = 0; i <= n; i++){
    B.push_back(0);
    I.push_back(A.end());
  }
  cout << F() << endl;
}