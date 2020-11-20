# include <bits/stdc++.h>
# define ll long long int
using namespace std;

void kush_gupta(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

int main(){
	kush_gupta();
	ll k=0;
	cin>>k;
	while(k--){
		string s;
		cin>>s;
		string t;
		cin>>t;
		if (t.length()>s.length()){
			cout<<"NO\n";
		}
		else{
			bool flag=1;
			ll i=0,j=0;
			for (ll i=0;i<t.length();i++){
				if (s[j]!=t[i]){
					if (j+1>=s.length()){
						flag=0;
						break;
					}
					else if (s[j]=='-' && s[j+1]=='-'){
						j++;
					}
					else if (s[j]=='-' && s[j+1]=='+'){
						flag=0;
						break;
					}
					else if (s[j]=='+'){
						flag=0;
						break;
					}
				}
				j++;
			}
			if (flag==1 && j==s.length()){
				cout<<"YES\n";
			}
			else{
				cout<<"NO\n";
			}
		}
	}
	return 0;
}