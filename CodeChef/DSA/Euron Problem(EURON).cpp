# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define vi std::vector<int>
# define vll std::vector<ll>

void fastIO(){
	ios::sync_with_stdio(0);
   	cin.tie(0);
    cout.tie(0);
}
ll inversions=0;	//global variable

void merge(std::vector<ll> &array,ll l,ll m,ll r){
	ll n1=m-l+1;
	ll n2=r-m;
	ll i=0,j=0,k=0;
	std::vector<ll> temp_a(n1);
	std::vector<ll> temp_b(n2);
	rep(i,0,n1){
		temp_a[i]=array[l+i];
	}
	rep(j,0,n2){
		temp_b[j]=array[m+j+1];
	}
	i=0;j=0;k=l;
	while(i<n1 && j<n2){
		if (temp_a[i]<=temp_b[j]){
			array[k++]=temp_a[i++];
		}
		else{
			array[k++]=temp_b[j++];
			inversions+=temp_a.size()-i;
		}
	}
	while(i<n1){
		array[k++]=temp_a[i++];
	}
	while(j<n2){
		array[k++]=temp_b[j++];
	}
}

void mergeSort(std::vector<ll>& array,ll l,ll r){
	if (l<r){
		ll m=l+(r-l)/2;
		mergeSort(array,l,m);
		mergeSort(array,m+1,r);
		merge(array,l,m,r);
	}
}

int main()
{
	fastIO();
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
   	freopen("output.txt", "w", stdout) ;
   	#endif
	ll n=0;
	cin>>n;
	std::vector<ll> inputs(n);
	for (ll i=0;i<n;i++){
		cin>>inputs[i];
	}
	mergeSort(inputs,0,n-1);
	cout<<inversions<<endl;
	return 0;
}