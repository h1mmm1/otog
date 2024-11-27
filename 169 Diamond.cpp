#include<bits/stdc++.h>
using namespace std;
char a[2050][2050];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	memset(a,' ',sizeof a);
	string s="*^";
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
	 	for(int j=1;j<=n;j++){
	 		if(abs(i-(n/2+1))+abs(j-(n/2+1))<=n/2){
	 			if((n/2+1)%2!=0){
		 			if(i%2==0){
		 				if(j%2==0) a[i][j]='*';
	 					else a[i][j]='^';
					 }
					 else {
	 					if(j%2!=0) a[i][j]='*';
	 					else a[i][j]='^';
					 }	 				
				 }
				else{
		 			if(i%2!=0){
		 				if(j%2==0) a[i][j]='*';
	 					else a[i][j]='^';
					 }
					 else {
	 					if(j%2!=0) a[i][j]='*';
	 					else a[i][j]='^';
					 }					
				}
			}
		 }
	}
	a[n/2+1][n/2+1]='N';
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout << a[i][j];
		}
		cout << "\n";
	}
}
