#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int h1,h2,b1,b2,x,y,ans=0;
	cin >> h1 >> h2 >> b1 >> b2 >> x >> y;
	for(int i=0;i<=min(h1,b1);i++){
		for(int j=0;j<=min(h2,b2);j++){
			for(int k=0;k<=min(h1,b2);k++){
				for(int p=0;p<=min(h2,b1);p++){
					if(i+k>h1 || j+p>h2 || i+p>b1 || j+k>b2) continue;
					ans=max(ans,min(i+j,x)+min(k+p,y));					
				}

			}
		}
	}
	cout << ans;
}
