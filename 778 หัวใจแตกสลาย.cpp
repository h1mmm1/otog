#include<bits/stdc++.h>
using namespace std;
queue<int> q;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,l,r,sum=0,x;
  cin >> n >> l >> r;
  q.push(n);
  while(!q.empty()){
    x=q.front();
    q.pop();
    if(x<l+r){
      sum++;
      continue;
    }
    q.push(x*r/(l+r));
    q.push(x*l/(l+r));
  }
  cout << sum;
}
