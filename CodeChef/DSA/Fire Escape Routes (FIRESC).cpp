# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define ld long double
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define vi std::vector<int>
# define vll std::vector<ll>
# define vp vector <pair <ll,ll> >
# define vpp vector <pair <pair <ll,ll>,ll> >
# define pp pair <pair <ll,ll>,ll>
# define pb(x) push_back(x)
# define w(x) ll x=0; cin>>x; while(x--)
# define endl '\n'

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

ll find(vll &parent,ll x){
  if(parent[x]==x){
    return x;
  }
  ll res=find(parent,parent[x]);
  parent[x]=res;
  return res;
}

void unyn(vll &parent,ll x,ll y){
  ll p1=find(parent,x);
  ll p2=find(parent,y);

  parent[p1]=p2;
}

int main()
{
	kush_gupta();
	w(test_cases){
    ll n=0,m=0;
    cin>>n>>m;
    vll parent(n+1);
    rep(i,1,n+1){
      parent[i]=i;
    }
    ll x=0,y=0;
    rep(i,0,m){
      cin>>x>>y;
      unyn(parent,x,y);
    }
    vll arr(n+1,0);
    rep(i,1,n+1){
      ll temp=find(parent,i);
      arr[temp]++;
    }
    ll prod=1;
    ll res=0;
    rep(i,1,n+1){
      if(arr[i]!=0){
        prod=(prod*arr[i])%1000000007;
        res++;
      }
    }
    cout<<res<<" "<<prod<<endl;
  }
	return 0;
}