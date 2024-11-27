#include<bits/stdc++.h>
using namespace std;
using pii=pair<char,char>;
const int N=1000;
bool chk[N];
string a[N],s;
vector<char> g[N];
bool vis[N];
vector<string> ans;

void rec(char c){
	ans.push_back(s);	
	for(auto e:g[c]){
		if(vis[e]){
			cout << "!";
			exit(0);
		}
		vis[e]=true;
		s+=e;
		rec(e);
		vis[e]=false;
		s.pop_back();
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,o=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		for(auto e:a[i]){
			if(e<'a' || e>'z') continue;
			if(chk[e]==false){
				chk[e]=true;
				o++;
			}			
		}

	}
	for(int i=2;i<=n;i++){
		int cnt=0;
		while(a[i-1][cnt]==a[i][cnt] && cnt<min(a[i].size(),a[i-1].size())) cnt++;
		if(cnt<min(a[i].size(),a[i-1].size())) g[a[i-1][cnt]].push_back(a[i][cnt]);
		
	}
	for(char i='a';i<='z';i++){
		vis[i]=true;
		s+=i;
		rec(i);
		vis[i]=false;
		s.pop_back();
	}
	int mx=0;
	string str;
	for(auto e:ans){
		if(mx<e.size()){
			mx=e.size();
			str=e;
		}
	}
	if(str.size()==o) cout << str;
	else cout << "?";
//	cout << str.size() << ' ' << str << ' ' << o;
}
//a b c d e f g h i j k l m n o p q r s t u v w x y z
