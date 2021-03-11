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

bool isValid(ll x){
	ll d1=x%10;
	x/=10;
	ll d2=x;
	if ( (d1==0 || d1==1 || d1==2 || d1==5 || d1==8) 
		 and
		 (d2==0 || d2==1 || d2==2 || d2==5 || d2==8)
	   ){
		return true;
	}
	return false;
}

void change(ll &x){
	if (x==2)
		x=5;
	else if (x==5)
		x=2;
}

bool comp(ll h,ll m,ll hour,ll min){
	ll hh=0,mm=0,d1=0,d2=0;
	d1=(min%10);
	min/=10;
	d2=min;
	change(d1);
	change(d2);
	hh=d1*10+d2;

	d1=(hour%10);
	hour/=10;
	d2=hour;
	change(d1);
	change(d2);
	mm=d1*10+d2;
	if (hh<h and mm<m){
		return true;
	}
	return false;
}

void kush_gupta_solves(){
	w(t){
		ll h=0,m=0;
		cin>>h>>m;
		ll hour=0,min=0;
		char ch;
		cin>>hour>>ch>>min;
		while(1){
			if ( isValid(hour) and isValid(min) and
				 comp(h,m,hour,min) ){
				if (hour<10)	cout<<0;
				cout<<hour<<":";
				if (min<10)		cout<<0;
				cout<<min<<endl;
				break;
			}
			else{
				min=(min+1)%m;
				if (min==0){
					hour=(hour+1)%h;
				}
			}
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