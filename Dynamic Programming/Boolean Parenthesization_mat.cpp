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

ll mat[1001][1001][2];

ll solve(string s,ll i,ll j,bool op){
  if(i>j){
    return false;
  }
  if(i==j){
    if(op==true){
      return s[i]=='T';
    }
    else{
      return s[i]=='F';
    }
  }
  stringstream ss;
  ss<<i<<" "<<j<<" "<<op;
  string temp,temp2;
  while(ss>>temp2){
    temp+=temp2;
  }
  //cout<<temp<<endl;
  if(mp.find(temp)!=mp.end()){
    return mp[temp];
  }
  ll ans=0;
  for(ll k=i+1;k<=j-1;k+=2){
    ll lt=solve(s,i,k-1,true);
    ll lf=solve(s,i,k-1,false);
    ll rt=solve(s,k+1,j,true);
    ll rf=solve(s,k+1,j,false);
    if(s[k]=='&'){
      if(op==true){
        ans+=lt*rt;
      }
      else{
        ans+=lf*rt+lt*rf+lf*rf;
      }
    }
    else if(s[k]=='|'){
      if(op==true){
        ans+=(lt*rt)+(lt*rf)+(lf*rt);
      }
      else{
        ans+=(lf*rf);
      }
    }
    else if(s[k]=='^'){
      if(op==true){
        ans+=(lt*rf)+(lf*rt);
      }
      else{
        ans+=(lt*rt)+(lf*rf);
      }
    }
  }
  //cout<<ans<<endl;
  return mp[temp]=ans;
}

int main()
{
	kush_gupta();
	w(test_cases){
    ll n=0;
    string s;
    cin>>n>>s;
    mp.clear();
    ll res=solve(s,0,n-1,true);
    cout<<(res%1003)<<endl;
  }
	return 0;
}