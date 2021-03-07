// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    long long findSmallest(long long arr[], int n) {
        // code here
        long long res=1;
        for (long long i=0;i<n;i++){
            if (res<arr[i]){
                break;
            }
            else{
                res+=arr[i];
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findSmallest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends