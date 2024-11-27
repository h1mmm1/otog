#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
using namespace std;
using namespace __gnu_pbds;
using ll=long long int;

typedef tree<
  int,
  null_type,
  less_equal<int>,
  rb_tree_tag,
  tree_order_statistics_node_update> ordered_multiset;


int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	ordered_multiset s;
	int n,m,x,y;
	cin >> n >> m >> x >> y;
	for(int i=1;i<=n;i++){
		int a;
		cin >> a;
		s.insert(a);
	}
	x--,y--;
	while(m--){
		auto xx=s.find_by_order(x);
		auto yy=s.find_by_order(y);
		s.erase(yy);
		s.erase(xx);
		int sum1=*yy-*xx;
		int sum2=(*yy+*xx)/2;
		s.insert(sum1);
		s.insert(sum2);
	}
	for(auto e:s) cout << e << " ";
}

