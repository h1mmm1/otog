  #include<bits/stdc++.h>
  using namespace std;
  bool a[500005];

  int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int q;
    cin >> q;
    while(q--){
      int n,ans=0;
      cin >> n;
      if(n==1){
        cout << '1' << "\n" << '1' << '\n';
        continue;
    }
      for(int i=2;i<n;i++){
        int x=i;
        if(n%x==0 && a[i]==false){
          for(int j=1;j*x<n;j++){
            //if(j*x>=n) break;
        //if(a[j*x]==false) ans++;	 	
            a[j*x]=true;
            //ans++;
          }
        }
      }
      for(int i=1;i<n;i++){
        if(a[i]==false) ans++;
      }
      cout << ans << "\n";
      for(int i=1;i<n;i++){
        if(a[i]==false) cout << i << ' ';
        a[i]=false;    	
    }
      cout << "\n";
    }
  }
