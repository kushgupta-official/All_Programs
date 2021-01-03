// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 
# define ll long long int
 // } Driver Code Ends


//User function Template for C++
void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
  #endif
}
class Solution
{
public:
    int micsandjury(int n, int m,int teams[])
    {
       priority_queue <ll> pq;
       for (ll i=0;i<m;i++){
        pq.push(teams[i]);
       }
       if (n!=m){
        ll diff=n-m;
        for (ll i=0;i<diff;i++){
          ll x=pq.top();
          pq.pop();
          x= x%2==0?(x/2):(x/2+1);
          // x/=2;
          pq.push(x);
        }
       }
       return pq.top();
    }
};


// { Driver Code Starts.
int main()
{
  kush_gupta();
    int t;
    cin >> t;
    while (t--)
    {
        int N;int M;
        
        cin >>N>>M;
        int teams[M];
        int i;
        for(i=0;i<M;i++)
        cin>>teams[i];
        
        Solution ob;
        int ans = ob.micsandjury(N,M,teams);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends