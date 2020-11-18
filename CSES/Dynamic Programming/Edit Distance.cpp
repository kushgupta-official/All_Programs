# include <bits/stdc++.h>

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
	string a,b;
	cin>>a>>b;
	int la=a.length(),lb=b.length();
	vector <vector <int> > t(la+1,vector <int> (lb+1,0));
	for (int i=0;i<=la;i++){
		t[i][0]=i;
	}
	for (int j=0;j<=lb;j++){
		t[0][j]=j;
	}
	for (int i=1;i<=la;i++){
		for (int j=1;j<=lb;j++){
			if (a[i-1]==b[j-1]){
				t[i][j]=t[i-1][j-1];
			}
			else{
				t[i][j]=min(t[i-1][j-1],min(t[i-1][j],t[i][j-1]))+1;
			}
		}
	}
	cout<<t[la][lb];
	return 0;
}