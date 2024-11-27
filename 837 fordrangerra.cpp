#include<bits/stdc++.h>
using namespace std;
char a[2005][4020];
void O(int n,int x,int y){
  for(int i=1;i<=2*n-1;i++){
    for(int j=1;j<=n;j++){
      if(i==1 || i==2*n-1 || j==1 ||j==n) a[i+x][j+y]='#';
    }
  }
}
void F(int n){
  for(int i=1;i<=2*n-1;i++){
    for(int j=1;j<=n;j++){
      if(i==1 || j==1 || i==n) a[i][j]='#';
    }
  }
}
void R(int n,int x,int y){
  for(int i=1;i<=2*n-1;i++){
    for(int j=1;j<=n;j++){
      if(i==1 || j==1 || i==n) a[i+x][j+y]='#';
      if(j==n && i<=n) a[i+x][j+y]='#';
      if(i>n && i-j==n-1) a[i+x][j+y]='#';
    }
  }  
}
void D(int n,int x,int y){
  for(int i=1;i<=2*n-1;i++){
    for(int j=1;j<=n;j++){
      if(i==1 || i==2*n-1 || j==1 || j==n) a[i+x][j+y]='#';    	
      if(j==n && i==1 || j==n && i==2*n-1) a[i+x][j+y]=' ';    	
    }
  }
}
void print(int n){
  for(int i=1;i<=2*n-1;i++){
    for(int j=1;j<=4*n+4;j++){
      cout << a[i][j];
    }
    cout << "\n";
  }
}
int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  memset(a,' ',sizeof a);
  int n;
  cin >> n;
  F(n);
  O(n,0,n+1);
  R(n,0,(n+1)*2);
  D(n,0,(n+1)*3);
  print(n);
}
