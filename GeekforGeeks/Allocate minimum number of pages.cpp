// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int v[], int n, int m) 
    {
        if (m>n)
            return -1;
        int low=INT_MAX,high=0;
        for (int i=0;i<n;i++){
            high+=v[i];
            low=min(v[i],low);
        }
        int res=0;
        while(low<=high){
            int mid=(low+high)>>1;
            // cout<<mid<<endl;
            int allocated=1,s=0;
            for (int i=0;i<n;i++){
                if (v[i]>mid){
                    allocated=m+1;
                    break;
                }
                if (s+v[i]<=mid){
                    s+=v[i];
                }
                else{
                    s=v[i];
                    allocated++;
                }
            }
            // cout<<"all="<<allocated<<endl;
            if (allocated<=m){
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends