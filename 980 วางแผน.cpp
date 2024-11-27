#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
priority_queue<pii,vector<pii>,greater<pii>> q;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--){		
		int n;
		cin >> n;
		q.push({0,n});
//		q.push({1,n+2});
//		q.push({1,n-1});
		while(!q.empty()){
			int l=q.top().first;
			int x=q.top().second;
			q.pop();
//			cout << x << ' ' << l << "\n";
			if(x<=5){
//				mn=min(mn,l);
				cout << l+x-1 << "\n";
				break;
			}
//			if(vis[x]) continue;
//			vis[x]=true;			

			if(x%3==0){
				q.push({l+3,x/3});
			}
			else{
				q.push({l+1,x+2});
				q.push({l+1,x-1});
								
			}
//			if(q.top().second==n) q.pop();
		}
		while(!q.empty()) q.pop();
	}
}
