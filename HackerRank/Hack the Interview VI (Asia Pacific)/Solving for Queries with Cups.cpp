# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define vi std::vector<int>
# define vll std::vector<ll>
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

int main()
{
    kush_gupta();
    ll n=0,m=0,s=0,q=0;
  cin>>n>>m>>s>>q;
  map <ll,ll> ump;
  while(m--){
    ll temp=0;
    cin>>temp;
    ump[temp]=1;
  }
  while(s--){
    ll a=0,b=0;
    cin>>a>>b;
    if(ump.find(a)!=ump.end() && ump.find(b)==ump.end()){
      ump.erase(a);
      ump[b]=1;
    }
    else if(ump.find(a)==ump.end() && ump.find(b)!=ump.end()){
      ump.erase(b);
      ump[a]=1;
    }
  }
  /*for (auto a : ump){
    cout<<a.first<<endl;
    //mp[a.first]=count++;
  }*/
  map<ll,ll> mp;
  ll count=1;
  for (auto a : ump){
    //cout<<a.first<<endl;
    mp[a.first]=count++;
  }
  auto b=mp.begin();
  auto e=mp.end();
  while(q--){
    ll l=0,r=0;
    cin>>l>>r;
    ll x=0,y=0;
    
    auto ite=mp.lower_bound(l);
    if(ite!=e){
      if(ite!=b || l==(*b).first){
        x=(*ite).second;
      }
      else{
        x=0;
      }
    }
    else{
      ite--;
      x=(*ite).second;
    }


    ite=mp.lower_bound(r);
    if(ite!=e){
      if(ite!=b || r==(*b).first){
        y=(*ite).second;
      }
      else{
        y=0;
      }
    }
    else{
      ite--;
      y=(*ite).second;
    }
    //cout<<x<<" "<<y<<" ";
    if(l==r){
      if(mp.find(l)==e){
        cout<<0<<" ";
      }
      else{
        cout<<1<<" ";
      }
    }
    else if(x==y){
      if(mp.find(l)!=e || mp.find(r)!=e){
        cout<<1<<" ";
      }
    }
    else{
      cout<<y-x+1<<" ";
    }
  }
    return 0;
}