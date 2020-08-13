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

bool comp(pair<char,ll> p1,pair<char,ll> p2){
  return p1.second>p2.second;
}

struct compare { 
    bool operator()(pair<char,ll> p1,pair<char,ll> p2)
    { 
      return p1.second>p2.second;
    } 
};

int main()
{
	kush_gupta();
	w(test_cases){
    priority_queue <pair <char,ll>,vector <pair<char,ll> >, compare> pq;
    string s;
    cin>>s;
    vll freq(s.length());
    rep(i,0,s.length()){
      cin>>freq[i];
    }
    rep(i,0,s.length()){
      pq.push(pair <char,ll> (s[i],freq[i]));
    }
    rep(i,0,s.length()){
      cout<<pq.top().first;
      pq.pop();
    }
  }
	return 0;
}