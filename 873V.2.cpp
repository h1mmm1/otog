#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<functional>
using namespace std;
using namespace __gnu_pbds;

typedef tree<
  int,
  null_type,
  less_equal<int>,
  rb_tree_tag,
  tree_order_statistics_node_update> ordered_muitiset;


int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ordered_muitiset s;
  int n;
  cin >> n;
  for(int i=1;i<=n;i++){
    int a;
    cin >> a;
    int v=s.order_of_key(a+1);
    cout << v << ' ';
    s.insert(a);
  }
}
