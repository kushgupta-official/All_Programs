/*Ph@n^0m Dec0d3r*/
/*----------------*/
/* 	^_HAR HAR MAHADEV_^
   	|Om namah shivaya|
*/
#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
#define f(i,a,b) for(int i=a;i<b;i++)
#define ll long long int
#define fast std::ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define pb(temp) push_back(temp)
#define mp make_pair
#define mod (ll)1000000007
using namespace boost::multiprecision;
using namespace std ;
typedef unsigned long long int ulli;

ulli gcd(ulli x,ulli y) {
	if(x==0) return y;
	return gcd(y%x,x);
}
ulli factorial(ulli n) {
	if (n == 0)
		return 1;
	return n * factorial(n - 1);
}
ll findS(ll s) {
	return (sqrtl(8*s + 1) - 1)/2;
}
ll prime(ll a) {
	if(a==1)return 0;
	if(a==2 || a==3)return true;
	if(a%2==0 ||a%3==0)return 0;
	for(ll i=5; i<=sqrt(a); i+=6)
		if(a%i==0 || a%(i+2)==0)
			return 0;

	return 1;
}
ll ncr(ll n, ll r) {
	ll ans=1;
	f(i,0,r) {
		ans*=(n-i)%mod;
		ans/=(i+1);
	}
	return ans;
}
ll fact[1000001] ;
void prepare_f() {
	for(int i=0; i<1000001; i++) {
		fact[i] = 1 ;
	}
	for(int i=1; i<1000001; i++) {
		fact[i] = (fact[i-1]*i)%mod ;
	}
}
ll fac[1000001];
ll power(ll x, ll y, ll p)
{
    ll res = 1;

    x = x % p;

    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;

        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
ll modInverse(ll n, ll p)
{
    return power(n, p-2, p);
}
ll nCrModPFermat(ll n, ll r, ll p)
{
   if (r==0)
      return 1;
    return (fac[n]* modInverse(fac[r], p) % p *modInverse(fac[n-r], p) % p) % p;
}
int main() {
	//prepare_f() ;
	ll p = mod ;
    fac[0] = 1;
    for (int i=1 ; i<=1000000; i++)
        fac[i] = fac[i-1]*i%p;

	int t ;
	cin >> t ;
	while(t--) {
		int n ;
		cin >> n ;
		string a,b;
		cin>>a>>b;
		ll l=a.size();
		ll one_max=0,one_min=0;

		f(i,0,a.size()) {
			if(a[i]=='1')
				one_max++;
			if(b[i]=='1')
				one_min++;
		}
		if(one_max<one_min) {
			ll temp=one_min;
			one_min=one_max;
			one_max=temp;
		}
		if(one_max+one_min>l) {
			ll dif=(one_max+one_min)-l;
			one_max-=dif;
			one_min-=dif;
		}
		cpp_int ans=0;
		do {
			ll tmp = fact[l]/fact[one_max+one_min] ;
			ans += nCrModPFermat(l,one_max+one_min,p) ;
			one_max--;
			one_min--;
		} while (one_min>=0);
		cout<<ans%mod<<endl;
	}
	return 0;
}
