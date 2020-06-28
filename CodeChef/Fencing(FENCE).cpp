# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define vi std::vector<int>
# define vll std::vector<ll>

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
   	freopen("output.txt", "w", stdout) ;
   	#endif
   	ll test_cases=0;
   	cin>>test_cases;
   	while(test_cases--){
   		ll n=0,m=0,k=0;
   		cin>>n>>m>>k;
   		//std::vector<vector<bool> >field (n, vector<bool>(m,0));
   		set<pair<ll,ll> > plants;
   		ll i=0,j=0;
   		while(k--){
   			cin>>i>>j;
   		//	field[i-1][j-1]=1;
   			plants.insert(pair<ll,ll>(i-1,j-1));
   		}
   		ll fences=0;
   		for (auto i:plants){
   			ll x=i.first;
   			ll y=i.second;
   			fences+=4;
   			if (plants.find(pair<ll,ll>(x+1,y))!=plants.end()){
   				fences--;
   			}
   			if (plants.find(pair<ll,ll>(x-1,y))!=plants.end()){
   				fences--;
   			}
   			if (plants.find(pair<ll,ll>(x,y+1))!=plants.end()){
   				fences--;
   			}
   			if (plants.find(pair<ll,ll>(x,y-1))!=plants.end()){
   				fences--;
   			}
   			/*if (x+1<n && field[x+1][y]){
   				fences--;
   			}
   			if (y+1<m && field[x][y+1]){
   				fences--;
   			}
   			if (x-1>=0 && field[x-1][y]){
   				fences--;
   			}
   			if (y-1>=0 && field[x][y-1]){
   				fences--;
   			}*/
   		}
   		cout<<fences<<endl;
   	}
	return 0;
}