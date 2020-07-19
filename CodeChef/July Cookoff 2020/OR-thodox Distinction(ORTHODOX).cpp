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
	w(test_cases){
    ll n=0;
    cin>>n;
    vll arr(n);
    set <ll> s;
    bool flag=true;
    for (ll i=0;i<n;i++){
      cin>>arr[i];
      if (s.find(arr[i])==s.end())
        s.insert(arr[i]);
      else
        flag=false;
    }
    ll sub=arr[0];
    if (flag!=false)
    for (ll i=1;i<n;i++){
      sub=sub|arr[i];
      //cout<<sub<<endl;
      if (s.find(sub)==s.end()){
        s.insert(sub);
      }
      else{
        flag=false;
        break;
      }
    }
    if (flag==false){
      cout<<"NO\n";
    }
    else{
      cout<<"YES\n";
    }
  }
	return 0;
}