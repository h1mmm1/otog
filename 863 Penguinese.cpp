#include<bits/stdc++.h>
using namespace std;
deque<string> s;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for(int i=1;i<=n;i++){
    string str;
    cin >> str;
    s.push_back(str);
  }
  for(int i=1;i<=2*n-1;i++){
    string str;
    cin >> str;
    if(str=="RIGHT"){
      string x=s.back();
      s.pop_back();
      s.pop_back();
      s.push_back(x);
    }
    else if(str=="LEFT"){
      s.pop_back();
    }
    else{
      string x=s.front();
      s.pop_front();
      s.push_back(x);
    }
  }
  cout << s.front();
}
