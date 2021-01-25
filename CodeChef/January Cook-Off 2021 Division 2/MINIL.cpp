# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define ld long double
# define loop(i,a,b) for(ll i=a;i<b;i++)
# define vi vector<int>
# define vll vector<ll>
# define vvl vector<vector <ll> >
# define vp vector <pair <ll,ll> >
# define vpp vector <pair <pair <ll,ll>,ll> >
# define pp pair <pair <ll,ll>,ll>
# define pb(x) push_back(x)
# define w(x) ll x=0; cin>>x; while(x--)
# define endl '\n'
# define mid(l,r) l+(r-l)/2
# define fi first
# define se second

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin) ;
  	freopen("output.txt", "w", stdout) ;
  #endif
}

int main()
{
	kush_gupta();
	#ifndef ONLINE_JUDGE
		auto __start = chrono::high_resolution_clock::now(); 
	#endif

	w(t){
		ll n=0,m=0;
		cin>>n>>m;
		vvl matrix(n+2,vector <ll> (m+2,0));
		char ch;
		for (ll i=1;i<=n;i++){
			for (ll j=1;j<=m;j++){
				cin>>ch;
				if (ch=='.'){
					matrix[i][j]=0;
				}
				else{
					matrix[i][j]=1;
				}
			}
		}

		ll opf=0,ops=0;
		for (ll i=1;i<=n;i++){
			for (ll j=1;j<=m;j++){
				if (i%2!=0){
					if (j%2!=0 and !matrix[i][j]){
						opf++;
					}
					else if (j%2==0 and matrix[i][j]){
						opf++;
					}
				}
				else{
					if (j%2==0 and !matrix[i][j]){
						opf++;
					}
					else if (j%2!=0 and matrix[i][j]){
						opf++;
					}
				}
			}
		}
		if ((n*m)%2==0){
			for (ll i=1;i<=n;i++){
				for (ll j=1;j<=m;j++){
					if (i%2!=0){
						if (j%2==0 and !matrix[i][j]){
							ops++;
						}
						else if (j%2!=0 and matrix[i][j]){
							ops++;
						}
					}
					else{
						if (j%2==0 and matrix[i][j]){
							ops++;
						}
						else if (j%2!=0 and !matrix[i][j]){
							ops++;
						}
					}
				}
			}	
		}
		else{
			ops=INT_MAX;
		}
		cout<<min(opf,ops)<<endl;
	}

	#ifndef ONLINE_JUDGE
		auto __end = chrono::high_resolution_clock::now(); 
		double __time_taken=chrono::duration_cast<chrono::nanoseconds>(__end - __start).count(); 
		__time_taken *= 1e-9; 
		cout<<"\nTime Taken : "<<fixed<< __time_taken << setprecision(9); 
		cout << " sec" << endl;
	#endif
	return 0;
}