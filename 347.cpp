#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=(3e4+5)*4;
ll tree[N];

ll query(int v,int l,int r,ll ql,ll qr){
  if(qr<l || r<ql) return 0;
  if(ql<=l && r<=qr) return tree[v];
  int mid=(l+r)/2;
  return max(query(v*2,l,mid,ql,qr),query(v*2+1,mid+1,r,ql,qr));
}

void update(int v,int l,int r,int pos,ll val){
  if(l==r) tree[v]=val;
  else{
    int mid=(l+r)/2;
    if(pos<=mid){
      update(v*2,l,mid,pos,val);
    }
    else update(v*2+1,mid+1,r,pos,val);
    tree[v]=max(tree[v*2],tree[v*2+1]);
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=m;i++){
    char c;
    cin >> c;
    if(c=='B'){
      ll x,y;
      cin >> x >> y;
      update(1,1,n,x,y);
    }
    else{
      ll x;
      cin >> x;
      cout << query(1,1,n,1,x) << "\n";
    }
  }
}

