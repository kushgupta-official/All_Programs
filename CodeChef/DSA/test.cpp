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
		vvl matrix(n+2,vector <ll> (m+2));
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
		// if i*j%2==0 than if !matrix[i][j]==1 op++
		ll operations=0;
		if ( (n*m) % 2!=0){
			if (matrix[1][1]==0){
				operations++;
				matrix[1][1]=1;
			}
		}
		for (ll i=1;i<=n;i++){
			for (ll j=1;j<=m;j++){
				// if (i>0 && !matrix[i-1][j]){
				// 	// mark(matrix,visited,n,m,i-1,j);
				// }
				// if (j>0 && !matrix[i][j-1]){
				// 	// mark(matrix,visited,n,m,i,j-1);
				// }
				if (!matrix[i][j]
					&& !matrix[i-1][j] 
					&& !matrix[i+1][j] 
					&& !matrix[i][j-1] 
					&& !matrix[i][j+1])
				{
					matrix[i][j]=1;
					operations++;
				}
				else{
					if (matrix[i][j] && i<n && matrix[i+1][j]){
						matrix[i+1][j]=0;
						operations++;
						j++;
						if (j>m){
							i++;
						}
						// mark(matrix,visited,n,m,i+1,j);
					}
					if (matrix[i][j] && j<m && matrix[i][j+1]){
						matrix[i][j+1]=1;
						operations++;
						j++;
						if (j>m){
							i++;
						}
						// mark(matrix,visited,n,m,i,j+1);
					}
				}
			}
		}
		cout<<operations<<endl;
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

// * . . *
// * . * .

// . * . *
// * . * .