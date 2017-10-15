#include <iostream>
#include <list>
#include <vector>
using namespace std;

list<int> A;
vector<bool> B;
vector<list<int>::iterator> I;
int base, mx = 0;
list<int>::iterator it = A.end();

bool F101(int x, int y);
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
    cout << *it << " ";
  cout << endl;
}

bool F101(int x, int y){
  cout << "101" << endl;
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
    if(z == w){
      A.push_back(z);
      return 1;
    }
    else{
      base = z;
      A.push_back(w);
      it = A.end()--;
      return 1;
    }
  }
  else{
    return 0;
  }
}

void F102(int x, int y){
  cout << "102" << endl;
  show();
  for(int i = x; i <= y; i++){
    if(B[i]){
      B[i] = 0;
    }
    else{
      A.push_back(i);
      break;
    }
  }
}

void F10(int a, int b, int c, int d){
  cout << "10" << endl;
  show();
  if(F101(a, b))
    F102(c, d);
  else
    F101(c, d);
}

void F01(int p, int x, bool d){
  cout << "01" << endl;
  show();
  int i;
  if(p == base){
    if(base + 1 == x) it = A.end();
    else base++;      
  }
  else if(p == x){
    (*it)--;
    if(base == x - 1) it = A.end();     
  }
  else{
    for(i = p - 1; i >= base; i--){
      if(B[i]) B[i] = 0;
      else break;
    }
    (*it) = i;
    if(i == base) it = A.end();
    if(d){
      for(i = p + 1; i <= x; i++){
        if(B[i]) B[i] = 0;
        else A.push_front(i);
      }
    }
    else{
      for(i = p + 1; i <= x; i++){
        if(B[i]) B[i] = 0;
        else A.push_back(i);
      }
    }
  }
}

bool F0(int p){
  cout << "0" << endl;
  show();
  int f, b;
  f = A.front();
  b = A.back();
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
      if(f == p){
        A.pop_back();
        return F();
      }
    }
  }
  return 0;
}

bool F1(int p){
  cout << "1" << endl;
  show();
  int q;
  while(cin >> q){
    if(q > p){
      B[p] = 1;
      p = q;
    }
    else{
      F10(mx+1, q-1, q+1, p-1);
      mx = p;
      return F();
    }
  }
  return 1;
}

int F20(int p){
  cout << "20" << endl;
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
      if(f == p){
        A.pop_back();
        return 0;
      }
    }
  }
  return -1;
}

bool F2(int p){
  cout << "2" << endl;
  show();
  vector<int> C;
  B[p] = 1;
  C.push_back(p);
  while(cin >> p && p > mx){
    B[p] = 1;
    C.push_back(p);
  }
  int z = F20(p);
  if(z == 1){
    for(int i = 0; i < C.size(); i++){
      if(C[i] > mx){
        for(int j = mx + 1; j < C[i]; j++){
          if(B[j]){
            A.push_back(-j);
            A.push_front(-j);
            I[j] = A.end()--;
          }
          else{
            A.push_front(j);
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
    return F();
  }
  else if(z == 0){
    for(int i = 0; i < C.size(); i++){
      if(C[i] > mx){
        for(int j = mx + 1; j < C[i]; j++){
          if(B[j]){
            A.push_back(-j);
            A.push_front(-j);
            I[j] = A.begin();
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
        x = A.back();
        while(x + C[i] <= 0){
          A.pop_back();
          if(x + C[i] == 0){
            A.erase(I[C[i]]);
            y = 1;
            break;
          }
        }
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
    return F();
  }
  return 0;
}

bool F(){
  cout << "F" << endl;
  show();
  int p;
  if(cin >> p){
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
  int n;
  cin >> n;
  for(int i = 0; i <= n; i++){
    B.push_back(0);
    I.push_back(A.end());
  }
  cout << (F() ? "Yes" : "No") << endl;
}