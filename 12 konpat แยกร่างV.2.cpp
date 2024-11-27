#include<bits/stdc++.h>
using namespace std;
string ans="99999999999999999999999999999999999999999999";
string s;

inline void rec(int x){
	//cout << x << ' ' << s << "\n";
  if(s.size()>ans.size() || x<1) return;
  if(x==1){
    if(ans.size()>s.size()){
      string str=s;
      for(int i=0;i<s.size()/2;i++){
        swap(str[i],str[s.size()-1-i]);
      }
//      cout << s <<' ' << str << "\n";
      ans=str;
    }
    else if(ans.size()==s.size()){
    	string str=s;
      for(int i=0;i<s.size()/2;i++){
        swap(str[i],str[s.size()-1-i]);
      }
//      cout << s <<' ' << str << "\n";      
      if(ans>str) ans=str;
    }
    return;
  }
  int k=9;
  if(s!="") k=s.back()-'0';
  for(int i=k;i>=2;i--){
    if(x%i==0){
    	s+=i+'0';
    	rec(x/i);
    	s.pop_back();
	}
  }
}

int main(){
  ios::sync_with_stdio(0);  
  int n;
  cin >> n;
  if(n<10){
  	cout << n;
  	return 0;
  }
  rec(n);
  if(ans=="99999999999999999999999999999999999999999999") cout << "-1";
  else cout << ans;
}
