#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;
int x[N],y[N],x2[N],y2[N],dis[20][N];
int ans=1e9,sum=0;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m,k,p;
  cin >> n >> m >> k >> p;
  for(int i=1;i<=k;i++){
    cin >> x[i] >> y[i] >> x2[i] >> y2[i];
  }  
  x[0]=x2[0]=y[0]=y2[0]=1;
  x[k+1]=x2[k+1]=n;
  y[k+1]=y2[k+1]=m;
  for(int i=0;i<20;i++){
    for(int j=0;j<=k+1;j++){
      dis[i][j]=1e9;
    }
  }
  dis[0][0]=0;
  for(int i=1;i<=p+1;i++){
    for(int j=0;j<=k+1;j++){
      for(int t=0;t<=k+1;t++){
      	if(j!=t){
	        dis[i][j]=min(dis[i][j],dis[i-1][t]+abs(x2[t]-x[j])+abs(y2[t]-y[j]));		  
		}
      }
      if(ans>dis[i][k+1]){
        ans=dis[i][k+1];
        sum=i;
      }
    }
  }
//  for(int i=1;i<=p;i++){
//  	for(int j=0;j<=k+1;j++){
//  		cout << dis[i][j] << ' ';
//	  }
//	  cout << '\n';
//  }
  cout << ans << " " << sum-1 << "\n";
} 

