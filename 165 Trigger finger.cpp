#include<bits/stdc++.h>
using namespace std;
int un[1000005];
int n[1000005];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  n[0]=1;
  int x=s.size();
  for(int i=1;i<=x;i++){
    if(s[i-1]<='Z' && s[i-1]>='A'){
      un[i]=min(n[i-1]+1,un[i-1]+1);
      n[i]=min(n[i-1],un[i-1]+1);
    }
    else if(s[i-1]<='z' && s[i-1]>='a'){
      n[i]=min(n[i-1]+1,un[i-1]+1);
      un[i]=min(n[i-1]+1,un[i-1]);
    }
  }
  cout << min(un[x],n[x]);
}
//https://cses.fi/problemset/task/2428
/*
           C o m p u t e r O l y m p i c K K U n a j a
Capl    1  1 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3 3 4 5 5 5
 
no Capl 0  1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 3 4 4 4 4 4 4
  */

