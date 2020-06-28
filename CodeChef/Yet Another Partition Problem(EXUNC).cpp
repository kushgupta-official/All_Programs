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
   	ll n=0,q=0;
   	cin>>n>>q;
   	vll array(n);
   	vll sub_arrays(n);
   	ll current=1;
   	rep(i,0,n){
   		cin>>array[i];
   		if (i!=0){
   			if (array[i]%array[i-1]==0){
   				sub_arrays[i]=current;
   			}	
   			else{
   				sub_arrays[i]=++current;
   			}
   		}
   		else{
   			sub_arrays[i]=current;
   		}
   	}
   	rep(i,0,n){
   		cout<<sub_arrays[i]<<" ";
   	}
   	ll x=0,y=0,z=0;
   	rep(i,0,q){
   		cin>>x;
   		if(x==1){
   			cin>>y;
   			cin>>z;
   		}
   		else{
   			cin>>y;
   		}
   	}
	return 0;
}