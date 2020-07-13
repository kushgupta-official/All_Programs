#pragma GCC optimize("Ofast,unroll-loops")
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <ratio>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
/*order_of_key(val): returns the no. of values less than val
find_by_order(k): returns the iterator to kth largest element.(0 - based)*/
typedef long double LD;
typedef long long ll;
#define int ll
#define pb push_back
#define mp make_pair
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define all(v) v.begin(),v.end()
#define sortall(x) sort(all(x))
#define tr(it,a) for(auto it=a.begin();it!=a.end();it++)
#define PI 3.1415926535897932384626
typedef map<int, int> mii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
#define F first
#define S second
#define PQ(type) priority_queue<type>
#define PQD(type) priority_queue<type,vector<type>,greater<type> >
#define WL(t) while(t --)
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
#define sqr(x) ((x)*(x))
#define inrange(i,a,b) ((i>=min(a,b)) && (i<=max(a,b)))


#define si(x) scanf("%lld",&x)
#define ss(x) scanf("%s",s)

#define pi(x) printf("%lld\n",x)
#define ps(x) printf("%s",x)

#define deb(x) cout<<#x <<"="<< x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<"."<<#y<<"="<<y<<endl
#define FLUSH fflush(stdout)
#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

const int MAXN = 1000005;
const int SQRTN = 1003;
const int LOGN = 22;
const double Pi = acos(-1);

#ifdef int
const int INF = 1e16;
#else
const int INF = 1e9;
#endif

const int MOD = 1000000007;
const int FMOD = 998244353;
const double eps = 1e-9;


template<typename T> T gcd(T a, T b) {return (b ? __gcd(a, b) : a);}
template<typename T> T lcm(T a, T b) {return (a * (b / gcd(a, b)));}
int add(int a, int b, int c = MOD) {int res = a + b; return (res >= c ? res - c : res);}
int mod_neg(int a, int b, int c = MOD) {int res; if (abs(a - b) < c)res = a - b; else res = (a - b) % c; return (res < 0 ? res + c : res);}
int mul(int a, int b, int c = MOD) {ll res = (ll)a * b; return (res >= c ? res % c : res);}
int muln(int a, int b, int c = MOD) {ll res = (ll)a * b; return ((res % c) + c) % c;}
ll mulmod(ll a, ll b, ll m = MOD) {ll q = (ll)(((LD)a * (LD)b) / (LD)m); ll r = a * b - q * m; if (r > m)r %= m; if (r < 0)r += m; return r;}
template<typename T>T expo(T e, T n) {T x = 1, p = e; while (n) {if (n & 1)x = x * p; p = p * p; n >>= 1;} return x;}
template<typename T>T power(T e, T n, T m = MOD) {T x = 1, p = e; while (n) {if (n & 1)x = mul(x, p, m); p = mul(p, p, m); n >>= 1;} return x;}
template<typename T>T extended_euclid(T a, T b, T &x, T &y) {
	T xx = 0, yy = 1; y = 0; x = 1; while (b) {
		T q = a / b, t = b; b = a % b; a = t; \
		t = xx; xx = x - q * xx; x = t; t = yy; yy = y - q * yy; y = t;
	} return a;
}
template<typename T>T mod_inverse(T a, T n = MOD) {T x, y, z = 0; T d = extended_euclid(a, n, x, y); return (d > 1 ? -1 : mod_neg(x, z, n));}
vector<int> prime;
vector<int> factors(100000 + 1);
void simpleSieve()
{
	bool mark[100000 + 1];
	memset(mark, false, sizeof(mark));

	for (int i = 2; i <= 100000; ++i) {
		if (mark[i] == false) {
			// If not marked yet, then its a prime
			prime.push_back(i);
			for (int j = i; j <= 100000; j += i)
				mark[j] = true;
		}
	}
}
void factor() {
	for (auto i : prime) {
		for (int j = i; j <= 100001; j += i) {
			factors[j]++;
		}
	}
	/*for (int i=2;i<factors.size();i++){
		cout<<factors[i]<<endl;
	}*/
}
signed main() {
	FAST_IO;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	simpleSieve();
	factor();
	int t;
	cin >> t;
	while (t--) {
		int a, b, k;
		int c = 0;
		cin >> a >> b >> k;
		for (int i = a; i <= b; i++) {
			if (factors[i] == k) c++;
		}
		cout << c << endl;
	}
	return 0;
}