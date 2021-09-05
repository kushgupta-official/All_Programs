// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int a[], int n)
    {
      unordered_map <int,int> mp;
      for (int i=0;i<n;i++){
          mp[a[i]]=1;
      }
      int mx=1,cnt=0;
      for (int i=0;i<n;i++){
          if (mp[a[i]-1]==0){
              cnt=0;
              int j=a[i];
            //   cout<<a[i]<<endl;
              while(mp[j]){
                  cnt++;
                  j++;
              }
              mx=max(mx,cnt);
          }
      }
      return mx;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends