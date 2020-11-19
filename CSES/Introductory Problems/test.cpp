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

int n=3;
vector <int> permutation;
vector <bool> chosen(n+1,0);

void display(){
	for (int i=0;i<permutation.size();i++){
		cout<<permutation[i]<<" ";
	}
	cout<<endl;
}

void generate_permutations(){
	if (permutation.size()==n){
		display();
	}
	else{
		for (int i=1;i<=n;i++){
			if (chosen[i])	continue;
			permutation.push_back(i);
			chosen[i]=true;
			generate_permutations();
			permutation.pop_back();
			chosen[i]=false;
		}
	}
}

int main(){
	kush_gupta();
	generate_permutations();
	return 0;
}