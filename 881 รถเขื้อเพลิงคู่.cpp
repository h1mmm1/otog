#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
deque<pair<pii,int>> dq;
const int N=1e7+1;
long long int dp[N];
int a[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,v;
  scanf("%d%d",&n,&v);
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
  }
  for(int i=1;i<=n;i++){
    while(!dq.empty() && dq.back().first.first>=a[i]) dq.pop_back();
    if(!dq.empty()){
      int x=dq.front().first.first;
      int oil=dq.front().first.second;
      int id=dq.front().second;
      dq.pop_front();
      if(oil<v){
        dq.push_front({{x,oil+1},id});
        dq.push_back({{a[i],1},i});
      }
      else{
        if(!dq.empty()){
          int xx=dq.front().first.first;
          int ooil=dq.front().first.second;
          int idd=dq.front().second;
          dq.pop_front();
          dq.push_front({{xx,v-idd+id+1},idd});
          dq.push_back({{a[i],1},i});
        }
        else dq.push_back({{a[i],v-i+id+1},i}); 
      }
    }
    else dq.push_back({{a[i],1},i});
    dp[i]=dq.front().first.first+dp[i-1];
  }
  long long int ans=dp[n];
  while(!dq.empty()) dq.pop_back();
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
  }
  for(int i=1;i<=n;i++){
    while(!dq.empty() && dq.back().first.first>=a[i]) dq.pop_back();
    if(!dq.empty()){
      int x=dq.front().first.first;
      int oil=dq.front().first.second;
      int id=dq.front().second;
      dq.pop_front();
      if(oil<v){
        dq.push_front({{x,oil+1},id});
        dq.push_back({{a[i],1},i});
      }
      else{
        if(!dq.empty()){
          int xx=dq.front().first.first;
          int ooil=dq.front().first.second;
          int idd=dq.front().second;
          dq.pop_front();
          dq.push_front({{xx,v-idd+id+1},idd});
          dq.push_back({{a[i],1},i});
        }
        else dq.push_back({{a[i],v-i+id+1},i}); 
      }
    }
    else dq.push_back({{a[i],1},i});
    dp[i]=dq.front().first.first+dp[i-1];
  }
  printf("%lld",ans+dp[n]);
//  cout << "\n";
//  cout << ans << ' ' << dp[n];
//  cout << "\n";
//  for(int i=1;i<=n+1;i++) cout << dp[i] << ' ';
}
/*
6 4
3 6 5 4 6 1
3 6 5 4 6 1

4 2
3 1 1 4
1 5 1 6

5 2
1 100 100 1 1
1 100 100 1 1
*/
