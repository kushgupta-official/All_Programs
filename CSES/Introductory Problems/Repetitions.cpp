# include <bits/stdc++.h>
# define ll long long int
using namespace std;

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
	string s;
	cin>>s;
	ll res=INT_MIN,temp=1;
	for (ll i=1;i<s.size();i++){
		if (s[i]==s[i-1]){
			temp++;
		}
		else{
			temp=1;
		}
		res=max(res,temp);
	}
	if (s.size()==1){
		res=1;
	}
	cout<<res;
	return 0;
}