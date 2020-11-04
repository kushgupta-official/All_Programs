// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

bool dpSol(int n,int arr[],int sum){
    if (sum==0){
        return 1;
    }
    if (n==0){
        return 0;
    }
    
    if (arr[n-1]<=sum){
        return dpSol(n-1,arr,sum-arr[n-1])||dpSol(n-1,arr,sum);
    }
    else{
        return dpSol(n-1,arr,sum);
    }
}

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for (int i=0;i<N;i++){
            sum+=arr[i];
        }
        if (sum%2!=0){
            return 0;
        }
        
        return dpSol(N,arr,sum/2);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends