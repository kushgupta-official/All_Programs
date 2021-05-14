# include <bits/stdc++.h>
# include <ext/pb_ds/assoc_container.hpp> 
# include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

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

template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
void kush_gupta_solves(){
	w(t){
		char board[3][3];
		ll winner=0;
		ll cx=0,c0=0;
		ll tcx=0,tc0=0;
		ll hori=0,verti=0,diag=0;
		ll won=-1;//for x-->0 and for 0-->1
		//for input and horizontol
		for (ll i=0;i<3;i++){
			tcx=0;
			tc0=0;
			for (ll j=0;j<3;j++){
				cin>>board[i][j];
				if (board[i][j]=='X'){
					cx++;
					tcx++;
				}
				else if (board[i][j]=='O'){
					c0++;
					tc0++;
				}
			}
			// cout<<tc0<<" "<<tcx<<endl;
			if (tcx==3 || tc0==3){
				if (tcx==3)	hori++;
				winner++;
				won= tcx==3 ? 0:1;
			}
		}
		//for vertical
		for (ll i=0;i<3;i++){
			tcx=0;
			tc0=0;
			for (ll j=0;j<3;j++){
				if (board[j][i]=='X'){
					tcx++;
				}
				else if (board[j][i]=='O'){
					tc0++;
				}	
			}
			// cout<<tc0<<" "<<tcx<<endl;
			if (tcx==3 || tc0==3){
				if (tcx==3)	verti++;
				winner++;
				won= tcx==3 ? 0:1;
			}
		}
		//Diagnol from 0
		tcx=0;
		tc0=0;
		for (ll i=0;i<3;i++){
			if (board[i][i]=='X'){
				tcx++;
			}
			else if (board[i][i]=='O'){
				tc0++;
			}
		}
		// cout<<tc0<<" "<<tcx<<endl;
		if (tcx==3 or tc0==3){
			if (tcx==3)	diag++;
			winner++;
			won= tcx==3 ? 0:1;
		}
		//Diagnol from 2
		tcx=0;
		tc0=0;
		for (ll i=0,j=2;j>=0;j--,i++){
			if (board[i][j]=='X'){
				tcx++;
			}
			else if (board[i][j]=='O'){
				tc0++;
			}
		}
		// cout<<tc0<<" "<<tcx<<endl;
		if (tcx==3 or tc0==3){
			if (tcx==3)	diag++;
			winner++;
			won= tcx==3 ? 0:1;
		}

		//solution calc

		//exceptional case->winner=2
		if (winner==2 and
			cx+c0==9 and
			cx==c0+1)
		{
			if ( (verti==1 and hori==1) or
				 (hori==1 and diag==1) or
				 (verti==1 and diag==1) or
				 (diag==2)
			   )
			{
				cout<<1<<endl;
				continue;
			}
		}
		//for third case
		// cout<<cx<<" "<<c0<<endl;
		if (!(cx==c0 or cx==c0+1)){
			cout<<3<<endl;
			continue;
		}
		if (cx<c0 or winner>1){
			cout<<3<<endl;
			continue;
		}
		else if (winner==1){
			if (won==0 and cx!=c0+1){
				cout<<3<<endl;
				continue;		
			}
			else if (won==1 and cx!=c0){
				cout<<3<<endl;
				continue;
			}
		}
		
		//for first case
		if (winner==1 or (cx+c0==9)){
			cout<<1<<endl;
		}
		else{
			cout<<2<<endl;
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		auto __start = chrono::high_resolution_clock::now(); 
		freopen("input.txt", "r", stdin) ;
  		freopen("output.txt", "w", stdout) ;
	#endif

	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	kush_gupta_solves();

	#ifndef ONLINE_JUDGE
		auto __end = chrono::high_resolution_clock::now(); 
		double __time_taken=chrono::duration_cast<chrono::nanoseconds>(__end - __start).count(); 
		__time_taken *= 1e-9; 
		cout<<"\nTime Taken : "<<fixed<< __time_taken << setprecision(9); 
		cout << " sec" << endl;
	#endif

	return 0;
}