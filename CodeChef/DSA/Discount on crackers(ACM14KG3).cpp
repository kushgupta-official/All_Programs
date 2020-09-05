# include <bits/stdc++.h>
# define ll long long int

using namespace std;

void kush_gupta(){
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}

bool visited[26];

bool dfs(const vector<vector<char> > &adj,char x,char y){
	visited[x-'a']=1;
	for (ll i=0;i<adj[x-'a'].size();i++){
		if (adj[x-'a'][i]==y){
			return true;
		}
		if(!visited[adj[x-'a'][i]-'a'] && dfs(adj,adj[x-'a'][i],y)){
			return true;
		}
	}
	return false;
}

int main(){
	kush_gupta();
	ll p=0;
	cin>>p;
	while(p--){
		vector<vector<char> > adj(26);
		string s,t;
		cin>>s>>t;
		ll m=0;
		cin>>m;
		string temp;
		char x,y;
		while(m--){
			cin>>temp;
			x=temp[0];y=temp[3];
			adj[x-'a'].push_back(y);
		}
		if(s.length()==t.length()){
			for (ll i=0;i<s.length();i++){
				memset(visited,0,sizeof(visited));
				if(s[i]==t[i]){
					continue;
				}
				else{
					if (dfs(adj,s[i],t[i])){
						s[i]=t[i];
					}
					else{
						break;
					}
				}
			}
		}
		if(s==t){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
	return 0;
}