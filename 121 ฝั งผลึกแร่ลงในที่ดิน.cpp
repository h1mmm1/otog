#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];

inline void ud(int i,int x){
  for(;i<N;i+=i&(-i)){
    a[i]+=x;
  }
}

inline int qry(int i){
  int cnt=0;
  for(;i>=1;i-=i&(-i)){
    cnt+=a[i];
  }
  return cnt;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=m;i++){
    int t;
    cin >> t;
    if(t==1){
      int l,x;
      cin >> x >> l;
      ud(l,x);
    }
    else{
      int l,r;
      cin >> l >> r;
      cout << qry(r)-qry(l-1) << "\n";
    }
  }
} 

