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

map <char,int> alphabets;

void solve(){
  w(test_cases){
    string text="";
    cin>>text;
    ll sum=0;
    for (ll i=0;i<text.size();i++){
      sum+=alphabets[text[i]];
    }
    cout<<sum<<endl;
  }
}

int main()
{
	kush_gupta();
  alphabets['A']=1;
  alphabets['B']=2;
  alphabets['C']=0;
  alphabets['D']=1;
  alphabets['E']=0;
  alphabets['F']=0;
  alphabets['G']=0;
  alphabets['H']=0;
  alphabets['I']=0;
  alphabets['J']=0;
  alphabets['K']=0;
  alphabets['L']=0;
  alphabets['M']=0;
  alphabets['N']=0;
  alphabets['O']=1;
  alphabets['P']=1;
  alphabets['Q']=1;
  alphabets['R']=1;
  alphabets['S']=0;
  alphabets['T']=0;
  alphabets['U']=0;
  alphabets['V']=0;
  alphabets['W']=0;
  alphabets['X']=0;
  alphabets['Y']=0;
  alphabets['Z']=0;
  solve();
	return 0;
}