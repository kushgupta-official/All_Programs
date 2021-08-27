// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public: 
    int matSearch (vector <vector <int>> &matrix, int n, int m, int target)
    {
        int i=0,j=m-1;
        while(i>=0 and i<n and j<m and j>=0){
            // cout<<i<<" "<<j<<endl;
            if (matrix[i][j]==target){
                return 1;
            }
            else if (target<matrix[i][j]){
                j--;
            }
            else{
                i++;
            }
        }
        return 0;
    }
};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}  // } Driver Code Ends