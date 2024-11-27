#include<bits/stdc++.h>
using namespace std;
char a[3500][3500];
void ot(int n,int m,int x,int y){
  for(int i=1;i<=m;i++){
    a[i+x][1+y]='#';
  }
}
void ol(int n,int m,int x,int y){
  for(int i=1;i<=m;i++){
    a[1+x][i+y]='#';
  }
}

void print(int n,int m){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cout << a[i][j];
    }
    cout << "\n";
  }
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
  memset(a,'.',sizeof a);
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    ot(n,3*n,2*n,n+i);
    ot(n,3*n,2*n,5*n+i);
    ol(n,3*n,n+i,2*n);
    ol(n,3*n,5*n+i,2*n);
    ol(n,5*n,n+i,7*n);
    ot(n,4*n,2*n,9*n+i);
    ot(n,3*n,2*n,13*n+i);
    ot(n,3*n,2*n,17*n+i);
    ol(n,3*n,n+i,14*n);
    ol(n,3*n,5*n+i,14*n);   
    ot(n,3*n,2*n,19*n+i);
    ol(n,4*n,n+i,20*n);
    ol(n,3*n,5*n+i,20*n);
    ot(n,2*n,3*n,23*n+i);
    ol(n,2*n,3*n+i,21*n);
  }
  print(7*n,25*n);
}

//https://vjudge.net/contest/197330#problem/Q


  
