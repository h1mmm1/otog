#include<bits/stdc++.h>
using namespace std;
int kmp[1000000];

void KMP(string p){
	int m=p.size();
	for(int i=1,j=0;i<m;i++){
		while(j>0 && p[i]!=p[j]) j=kmp[j-1];
		if(p[i]==p[j]) kmp[j]=++j;
	}
}
int KMP_1(string s, string p){
	int ans=0;
	int n=s.size();
	int m=p.size();
	for(int i=0,j=0;i<n;i++){
		while(j>0 && s[i]!=p[j]) j=kmp[j-1];
		if(s[i]==p[j]) ++j;
		if(j==m) ++ans;
	}
	return ans;
}


 
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i=1; ;i++){
		
	  	string s,p;
  		cin >> s >> p;
  		if(s==" ") return 0;
  		KMP(p);
  		cout << KMP_1(s,p) << "\n";	
		memset(kmp,0,sizeof kmp);	
	}

}
