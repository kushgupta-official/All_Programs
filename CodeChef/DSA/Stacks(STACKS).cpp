# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define vi std::vector<int>
# define vll std::vector<ll>
# define pb push_back

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
   	freopen("output.txt", "w", stdout) ;
   	#endif
   	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   	ll test_cases=0;
   	cin>>test_cases;
   	while(test_cases--){
   		std::multiset<ll> stack_tops;
   		ll n=0;
   		cin>>n;
   		ll input=0;
   		rep(i,0,n){
   			cin>>input;
   			if (!stack_tops.empty()){
   				auto itr=stack_tops.upper_bound(input);
   				if (itr!=stack_tops.end()){
   					stack_tops.erase(itr);
   					stack_tops.insert(input);
   				}
   				else{
   					stack_tops.insert(input);
   				}
   			}
   			else{
   				stack_tops.insert(input);
   			}
   		}
   		cout<<stack_tops.size()<<" ";
   		for (auto i:stack_tops){
   			cout<<i<<" ";
   		}
   		cout<<endl;
   	}
	return 0;
}
