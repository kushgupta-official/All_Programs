# include <bits/stdc++.h>
# define ll long long int
# define mod 1000000007
using namespace std;

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

int main(){
	kush_gupta();
	int n=0,x=0;
	cin>>n>>x;
	vector <int> cost(n),pages(n);
	for (int i=0;i<n;i++){
		cin>>cost[i];
	}
	for (int i=0;i<n;i++){
		cin>>pages[i];
	}
	vector<vector <int> > t(n+1,vector<int>(x+1,0));
	for (int i=1;i<=n;i++){
		for (int j=1;j<=x;j++){
			if (cost[i-1]<=j){
				t[i][j]=max(pages[i-1]+t[i-1][j-cost[i-1]],t[i-1][j]);
			}
			else{
				t[i][j]=t[i-1][j];
			}
		}
	}
	cout<<t[n][x];
	return 0;
}