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
	long long int n=0;
	cin>>n;
	while(n!=1){
		cout<<n<<' ';
		if (n%2==0){
			n/=2;
		}
		else{
			n=n*3+1;
		}
	}
	cout<<n;
	return 0;
}