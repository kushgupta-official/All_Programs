# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define ld long double
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
  w(t){
    string s,p;
    cin>>s>>p;
    sort(s.begin(), s.end());
    string temp=p; sort(temp.begin(), temp.end());
    ll j=0;
    string s2;
    ll i=0;
    for (i=0;i<s.size(),j<temp.size();i++){
      if(s[i]!=temp[j]){
        s2+=s[i];
      }
      else{
        j++;
      }
    }
    s2+=s.substr(i,s.size()-i);
    ll f=-1;
    for (i=0;i<s2.size();i++){
      if(s2[i]>p[0]){
        break;
      }
      if(s2[i]==p[0]){
        if(f==-1){
          f=i;
        }
      }
    }
    string res;
    if(f==-1){
      res=s2.substr(0,i)+p+s2.substr(i,s2.size()-i);
    }
    else{
      if(s2.substr(0,f)+p+s2.substr(f,s2.size()-f)<s2.substr(0,i)+p+s2.substr(i,s2.size()-i)){
        res=s2.substr(0,f)+p+s2.substr(f,s2.size()-f);
      }
      else{
        res=s2.substr(0,i)+p+s2.substr(i,s2.size()-i);
      }
    }
    cout<<res<<endl;
  }
	return 0;
}