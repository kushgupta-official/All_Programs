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
   	set <ll> position_of_subarrays;
   	ll current=1;
   	rep(i,0,n){
   		cin>>array[i];
   		if (i!=0){
   			if (array[i]%array[i-1]!=0){
   				position_of_subarrays.insert(i);
   			}
   		}
   		else{
   			position_of_subarrays.insert(i);
   		}
   	}
   	/*rep(i,0,n){
   		cout<<array[i]<<" ";
   	}
   	cout<<endl;
   	for (auto i:position_of_subarrays){
   		cout<<i<<" ";
   	}
   	cout<<endl;*/
   	ll x=0,y=0,z=0;
   	rep(i,0,q){
   		cin>>x;
   		if(x==1){
   			cin>>y;
   			cin>>z;
   			array[y-1]=z;
   			position_of_subarrays.insert(y-1);
   			if (y>1 && z%array[y-2]==0){
   				//cout<<"array[y-2] : "<<i<<" "<<array[y-2]<<endl;
   				position_of_subarrays.erase(y-1);
   			}
   			if (y<array.size() && array[y]%z==0){
   				position_of_subarrays.erase(position_of_subarrays.upper_bound(y-1));
   				//cout<<"array[y] : "<<i<<" "<<array[y]<<endl;
   			}
   		}
   		else{
   			cin>>y;
   			auto it=position_of_subarrays.upper_bound(y-1);
   			if (it!=position_of_subarrays.end()){
   				cout<<*(--it)+1;
   			}
   			else{
   				cout<<*(--position_of_subarrays.end())+1;
   			}
   			cout<<endl;
   		}
   	}
   	/*for (auto i:position_of_subarrays){
   		cout<<i<<" ";
   	}*/
	return 0;
}