#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
priority_queue<pii,vector<pii>,greater<pii>> q;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--){		
    int n;
    cin >> n;
    q.push({0,n});
    while(!q.empty()){
      int l=q.top().first;
      int x=q.top().second;
      q.pop();
//			cout << x << ' ' << l << "\n";
      if(x<=5){
        cout << l+x-1 << "\n";
        break;
      }
      if(x%3==0){
        q.push({l+3,x/3});
      }
      else if(x%3==1){
        q.push({l+4,(x+2)/3});
        q.push({l+4,(x-1)/3});
      }
      else{
        q.push({l+5,(x+2-1)/3});
        q.push({l+5,(x-1-1)/3});
        q.push({l+5,(x+2+2)/3});
      }
    }
    while(!q.empty()) q.pop();
  }
}

