// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int gap=ceil((n+m)/2.0);
            while(1){
                int i,j;
                // int gap=ceil((n+m)/2.0);
                for (i=0;i+gap<n;i++){
                    if (arr1[i]>arr1[i+gap]){
                        swap(arr1[i],arr1[i+gap]);
                    }
                }
                for (j = gap > n ? gap - n : 0;i<n and j<m;i++,j++){
                    if (arr1[i]>arr2[j]){
                        swap(arr1[i],arr2[j]);
                    }
                }
                for (j=0;j+gap<m;j++){
                    if (arr2[j]>arr2[j+gap]){
                        swap(arr2[j],arr2[j+gap]);
                    }
                }
                if (gap==1)
                    break;
                gap=ceil(gap/2.0);
            }
        } 
};

// { Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 
  // } Driver Code Ends