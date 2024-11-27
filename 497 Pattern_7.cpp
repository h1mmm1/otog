#include<bits/stdc++.h>
using namespace std;
char a[3050][3050];
int b[3050];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
  memset(a,'-',sizeof a);
	int n;
  cin >> n;
  int x=1,y=1;
  for(int k=1; ;k++){
    x=(k-1)*2+1;
    y=(k-1)*2+1;
    if(x>n/2+1) break;
    for(int l=1;l<=n-(k-1)*4;l++){
      a[x][y+l-1]='*';
    }
    y=y+n-(k-1)*4-1;
    for(int l=1;l<=n-(k-1)*4;l++){
      a[x+l-1][y]='*';
    }
    x=x+n-(k-1)*4-1;
    for(int l=1;l<=n-(k-1)*4;l++){
      a[x][y-l+1]='*';
    }
    y=y-n+(k-1)*4+1;
    for(int l=1;l<=n-(k-1)*4;l++){
      a[x-l+1][y]='*';
    }
    x=x-n+(k-1)*4+1;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cout << a[i][j];
    }
    cout << "\n";
  }
}
