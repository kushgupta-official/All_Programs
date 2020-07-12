# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define vi std::vector<int>
# define vll std::vector<ll>
# define w(x) ll x=0; cin>>x; while(x--)

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
 w(test_cases)
 {
    ll n=0,x=0;
    cin>>n>>x;
    vector<ll> inputs(n);
    for(ll i=0;i<n;i++){
        cin>>inputs[i];
    }
    ll days=0;
    sort(inputs.begin(),inputs.end());
    auto it = lower_bound(inputs.begin(), inputs.end(), x);
    ll lb = it - inputs.begin();
    for(ll i=lb;i<n;i++)
    {
    	if(x<inputs[i])
    	{
    		while(x<inputs[i])
    		{
    			x=2*x;
    			days++;
                //cout<<"days="<<days<<" x="<<x<<endl;
    		}
    		days++;
            //cout<<"days="<<days<<" x="<<x<<endl;
    	}
    	else{
            days++;
            //cout<<"days="<<days<<" x="<<x<<endl;
        }
    	x=2*inputs[i];
    }
    ll tot=lb+days;
    if(lb!=0)
    {
    	days=0;
    	lb--;
    	for(ll i=lb;i<n;i++)
    	{
    		if(x<inputs[i])
    		{
    			while(x<inputs[i])
    			{
    				x=2*x;
    				days++;
    			}
    			days++;
    		}
    		else
    		days++;
    		x=2*inputs[i];
    	}
    	ll ans=min(days+lb,tot);
    	cout<<ans<<endl;
    }
    else{
        cout<<tot<<endl;
    }
 }
 return 0;
}