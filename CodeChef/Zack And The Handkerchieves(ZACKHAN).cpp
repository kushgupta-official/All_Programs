# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define vi std::vector<int>
# define vll std::vector<ll>

void kush_gupta(){
	ios::sync_with_stdio(0);
   	cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
   	freopen("output.txt", "w", stdout) ;
   	#endif
}

ll gcd(ll length,ll breadth){
	ll temp;
	while(breadth!=0){
		temp=length%breadth;
		length=breadth;
		breadth=temp;
	}
	return length;
}

int main()
{
	kush_gupta();
	ll test_cases=0;
	cin>>test_cases;
	while(test_cases--){
		ll length=0,breadth=0;
		cin>>length>>breadth;
		cout<<gcd(length,breadth)<<endl;
	}
	return 0;
}