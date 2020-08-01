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
ll t[1001][1001],palin[1001][1001];
bool ispalindrome(string s,ll i,ll j){
  if(palin[i][j]!=-1){
    cout<<"k";
    return palin[i][j]==1;
  }
  if(i>=j){
    palin[i][j]=1;
    return true;
  }
  ll a=i,b=j;
  while(i<j){
    if(s[i]!=s[j]){
      palin[a][b]=0;
      return false;
    }
    i++;
    j--;
  }
  palin[a][b]=1;
  return true;
}

ll solve(string s,ll i,ll j){
  if(i>=j){
    return 0;
  }
  if(t[i][j]!=-1){
   // cout<<"yes";
    return t[i][j];
  }
  if(ispalindrome(s,i,j)==true){
    return t[i][j]=0;
  }
  ll mn=INT_MAX;
  for (ll k=i;k<j;k++){
    ll temp_ans=1;
    ll left,right;
    if(t[i][k]!=-1){
      left=t[i][k];
    }
    else{
      left=solve(s,i,k);
      t[i][k]=left;
    }
    if(t[k+1][j]!=-1){
      right=t[k+1][j];
    }
    else{
      right=solve(s,k+1,j);
      t[k+1][j]=right;
    }
    temp_ans+=left+right;
    if(temp_ans<mn){
      mn=temp_ans;
    }
  }
  return t[i][j]=mn;
}

int main()
{
	kush_gupta();
	w(test_cases){
    string s="";
    cin>>s;
    memset(t,-1,sizeof(t));
    memset(palin,-1,sizeof(palin));
    cout<<solve(s,0,s.length()-1)<<endl;
    /*for (ll i=0;i<s.length();i++){
      for(ll j=0;j<s.length();j++){
        cout<<t[i][j]<<" ";
      }
      cout<<endl;
    }*/
  }
	return 0;
}