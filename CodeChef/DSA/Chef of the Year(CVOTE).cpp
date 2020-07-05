# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define vi std::vector<int>
# define vll std::vector<ll>

int main()
{	
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
	ll n=0,m=0;
	cin>>n>>m;
	std::map<string, string> entries;
	std::map<string, ll> vote_chefs;
	std::map<string, ll> vote_countries;
	string chef="";
	string country="";
	rep(i,0,n){
		cin>>chef>>country;
		entries[chef]=country;
	}
	ll max_ch=-1;
	string max_chef="";
	ll max_co=-1;
	string max_country="";
	rep(i,0,m){
		cin>>chef;
		country=entries[chef];
		vote_chefs[chef]++;
		if (vote_chefs[chef]>max_ch){
			max_ch=vote_chefs[chef];
			max_chef=chef;
		}
		else if(vote_chefs[chef]==max_ch){
			if (chef<max_chef){
				max_chef=chef;
			}
		}

		vote_countries[country]++;
		if (vote_countries[country]>max_co){
			max_co=vote_countries[country];
			max_country=country;
		}
		else if(vote_countries[country]==max_co){
			if (country<max_country){
				max_country=country;
			}
		}
	}
	cout<<max_country<<endl<<max_chef;
	return 0;
}