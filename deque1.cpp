#include <iostream>
#include <deque>
using namespace std;

deque<int> c(deque<int> d){
  deque<int> d1;
  for(int i = 0; i < d.size(); i++) d1.push_back(d[i]);
  return d1;
}

bool f(deque<int> d0, deque<int> d1, int x, int y);

bool g(deque<int> d0, deque<int> d1, int x, int y){
  if(x == y){
    if(d0.empty()){
      return true;
    }
    else{
      y++;
      int z = d0.front();
      if(z > x){
        deque<int> d2 = c(d0);
        d2.pop_front();
        return g(d2, d1, z, y);
      }
      else{
        if(z == d1.front()){
          deque<int> d2 = c(d0);
          deque<int> d3 = c(d1);
          d2.pop_front();
          d3.pop_front();
          return f(d2, d3, x, y);
        }
        else if(z == d1.back()){
          deque<int> d2 = c(d0);
          deque<int> d3 = c(d1);
          d2.pop_front();
          d3.pop_back();
          return f(d2, d3, x, y);
        }
        else{
          return false;
        }
      }
    }
  }
  else if(x > y){
    if(d1.size() < 2){
      d1.push_back(y);
      return g(d0, d1, x, y + 1);
    }
    else{
      deque<int> d2 = c(d1);
      deque<int> d3 = c(d1);
      d2.push_back(y);
      d3.push_front(y);
      return g(d0, d2, x, y + 1) || g(d0, d3, x, y + 1);
    }
  }
  else{
    if(x == d1.front()){
      deque<int> d2 = c(d1);
      d2.pop_front();
      return f(d0, d2, x, y);
    }
    else if(x == d1.back()){
      deque<int> d2 = c(d1);
      d2.pop_back();
      return f(d0, d2, x, y);
    }
  }
}

bool f(deque<int> d0, deque<int> d1, int x, int y){
  if(d0.empty()){
    return true;
  }
  else{
    deque<int> d2 = c(d0);
    int z = d2.front();
    d2.pop_front();
    return g(d2, d1, z, y);
  }
}

int main(){
  int n, m;
  cin >> n;
  deque<int> d0, d1;
  for(int i = 0; i < n; i++){
    cin >> m;
    d0.push_back(m);
  }
  if(f(d0, d1, 0, 1) == false){
    cout << "No" << endl;
  }
  else{
    cout << "Yes" << endl;
  }
}