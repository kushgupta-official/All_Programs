// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> a){
        int i,j;
        for (i=n-2;i>=0;i--){
            if (a[i]<a[i+1]){
                break;
            }
        }
        if (i==-1){
            sort(a.begin(),a.end());
        }
        else{
            for (j=n-1;j>=0;j--){
                if (a[j]>a[i]){
                    break;
                }
            }
            swap(a[i],a[j]);
            int lo=i+1,hi=n-1;
            while(lo<=hi){
                swap(a[lo++],a[hi--]);
            }
        }
        return a;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends