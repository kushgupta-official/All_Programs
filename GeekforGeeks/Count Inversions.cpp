// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long arr[],long long l,long long m,long long r){
        long long temp[r-l+1];
        long long idx=0;
        long long inv_cost=0;
        long long i=l,j=m;
        while(i<m and j<=r){
            if (arr[i]<=arr[j]){
                temp[idx++]=arr[i++];
            }
            else{
                temp[idx++]=arr[j++];
                inv_cost+=m-i;
            }
        }
        while (i<m){
            temp[idx++]=arr[i++];            
        }
        while (j<=r){
            temp[idx++]=arr[j++];
        }
        for (long long k=0;k<r-l+1;k++){
            arr[l+k]=temp[k];
        }
        return inv_cost;
    }
    long long int mergeSort(long long arr[],long long l,long long r){
        long long int inv_cost=0;
        if (l<r){
            long long int m=l+(r-l)/2;
            inv_cost+=mergeSort(arr,l,m);
            inv_cost+=mergeSort(arr,m+1,r);
            inv_cost+=merge(arr,l,m+1,r);
        }
        return inv_cost;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        return mergeSort(arr,0,N-1);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends