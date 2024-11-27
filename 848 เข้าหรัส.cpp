#include<bits/stdc++.h>
using namespace std;
char _a[1005][1005];
string s;

void rec(int a,int b,int x,int y){
  bool chk=false,chk1=false;
  for(int i=a;i<=x;i++){
    for(int j=b;j<=y;j++){
      if(_a[i][j]=='1') chk=true;
      else if(_a[i][j]=='0') chk1=true;
    }
  }
  if(chk && !chk1) s+='1';
  else if(!chk && chk1) s+='0';
  else{
    s+='D';
    rec(a,b,(x+a)/2,(y+b)/2);
    
    if((y+b)/2+1<=y && a<=((x+a)/2)) rec(a,(y+b)/2+1,(x+a)/2,y);

    if((x+a)/2+1<=x && b<=(y+b)/2) rec((x+a)/2+1,b,x,(y+b)/2);

    if((x+a)/2+1<=x && (y+b)/2+1<=y) rec((x+a)/2+1,(y+b)/2+1,x,y);
  } 
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin >> _a[i][j];
    }
  }
  rec(1,1,n,m);
  cout << s;
}
