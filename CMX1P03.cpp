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

ll bc(ll n, ll k) 
{ 
	ll result = 1; 
	if (k > n - k) 
		k = n - k; 

	rep(i,0,k) { 
		result *= (n - i); 
		result /= (i + 1); 
	} 

	return result; 
} 


ll calcScore(string s1, string s2) 
{ 
	ll n1 = s1.size(); 
	ll n2 = s2.size(); 
	ll f1[26], f2[26]; 

	memset(f1,0,sizeof(f1)); 
	memset(f2,0,sizeof(f2)); 

	rep(i,0,n1) 
		f1[s1[i]-'a']++; 
	rep(i,0,n2) 
		f2[s2[i]-'a']++; 
	ll count = 1; 

	for (ll i = 0; i < 26; i++) 
		if (f2[i] != 0) { 
			if (f2[i] <= f1[i]) 
				count = count * bc(f1[i], f2[i]); 
			else
				return 0; 
		} 

	return count; 
} 

int main() {
	kush_gupta();
	w(months){
		string str1;
		cin>>str1; 
		ll n=0;
		cin>>n;
		string str2;
		ll score=0,max_score=0;
		string res_string;
		//ll flag=0;
		rep(i,0,n){
			cin>>str2;
			score=calcScore(str1, str2)%998244353;
			cout <<score<<endl;
			if(score>max_score){// || (score==max_score && str2<res_string)){
				max_score=score;
				res_string=str2;
			}
		}
		if(max_score==0){
			cout<<"No Research This Month\n";
		}
		else{
			cout<<res_string<<endl;
		}
	}
	return 0; 
} 
