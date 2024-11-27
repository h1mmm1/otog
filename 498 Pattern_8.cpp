#include<bits/stdc++.h>
using namespace std;
char a[3005][3005];
int m[3005];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  memset(a,'-',sizeof a);
  int n;
  cin >> n;
  int cnt=0,s=n,x=1,y=1;
  m[0]=n;
  for(int i=1;i<=n;i++){
    m[i]=m[i-1];
    if(i%2==0 && i!=2)  m[i]-=2;
  }
  while(s--){
    cnt++;
    if(cnt%4==1){
      for(int j=y;j<=m[cnt]+y-1;j++){
        a[j][x]='*';
      }       
      y=m[cnt]+y-1;
    }
      
    else if(cnt%4==2){
      for(int i=x;i<=m[cnt]+x-1;i++){
        a[y][i]='*';
      }
      x=m[cnt]+x-1;
    }
     
    else if(cnt%4==3){
      for(int j=y;j>=y-m[cnt]+1;j--){
        a[j][x]='*';
      }
      y=y-m[cnt]+1;
    }
    else if(cnt%4==0){
      for(int i=x;i>=x-m[cnt]+1;i--){
        a[y][i]='*';
      }
      x=x-m[cnt]+1;
    }
  }

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cout << a[i][j];
    }
    cout << "\n";
  }
}
