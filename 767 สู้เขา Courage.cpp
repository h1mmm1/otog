#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int m,a1,a2,a3;
    cin >> m >> a1 >> a2 >> a3;
    int a;
    cin >> a;
    int x[a+2];
    for(int i=1;i<=a;i++){
      cin >> x[i];
    }
    int b;
    cin >> b;
    int y[b+2];
    for(int i=1;i<=b;i++){
      cin >> y[i];
    }
    int c;
    cin >> c;
    int z[c+2];
    for(int i=1;i<=c;i++){
      cin >> z[i];
    }

    if(a!=0 && b==0 && c==0) cout << (a1-m)*a << "\n";
    else if(a!=0 && b!=0 && c==0){
      int dp[a+2][b+2];
      for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
          dp[i][j]=INT_MIN;
      }
    }
    dp[0][0]=0;
      for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
      if(dp[i][j]==INT_MIN) continue;	
          if(x[i+1]==y[j+1]){
            dp[i+1][j+1]=max(dp[i][j]+a2-m,dp[i+1][j+1]);
          }
          else{
            dp[i+1][j]=max(dp[i][j]+a1-m,dp[i+1][j]);
            dp[i][j+1]=max(dp[i][j]+a1-m,dp[i][j+1]);
          }
        }
      }
      cout << dp[a][b] << "\n";
//      for(int i=0;i<=a;i++){
//      	for(int j=0;j<=b;j++){
//      		cout << dp[i][j] << ' ';
//		  }
//		  cout << "\n";
//	  }
    }
    else{
      int dp[a+2][b+2][c+2];
      for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
          for(int k=0;k<=c;k++){
            dp[i][j][k]=INT_MIN;
          }
        }
      }
      dp[0][0][0]=0;
      for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
          for(int k=0;k<=c;k++){
            if(dp[i][j][k]==INT_MIN) continue;
            if(x[i+1]==y[j+1] && y[j+1]==z[k+1]){
              dp[i+1][j+1][k+1]=max(dp[i+1][j+1][k+1],dp[i][j][k]+a3-m);
            }
            else if(x[i+1]==y[j+1]){
              dp[i+1][j+1][k]=max(dp[i+1][j+1][k],dp[i][j][k]+a2-m);
              dp[i][j][k+1]=max(dp[i][j][k+1],dp[i][j][k]+a1-m);
            }
            else if(x[i+1]==z[k+1]){
              dp[i+1][j][k+1]=max(dp[i+1][j][k+1],dp[i][j][k]+a2-m);
              dp[i][j+1][k]=max(dp[i][j+1][k],dp[i][j][k]+a1-m);
            }
            else if(z[k+1]==y[j+1]){
              dp[i][j+1][k+1]=max(dp[i][j+1][k+1],dp[i][j][k]+a2-m);
              dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+a1-m);
            }
            else{
              dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+a1-m);
              dp[i][j+1][k]=max(dp[i][j+1][k],dp[i][j][k]+a1-m);
              dp[i][j][k+1]=max(dp[i][j][k+1],dp[i][j][k]+a1-m);
            }
          }
        }
      }
      cout << dp[a][b][c] << "\n";
    }
  }
}

