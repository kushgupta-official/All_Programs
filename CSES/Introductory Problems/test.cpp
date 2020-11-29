#include<bits/stdc++.h>
using namespace std::chrono; 

using namespace std;

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  	freopen("input.txt", "r", stdin) ;
  	freopen("output.txt", "w", stdout) ;
  #endif
}

int main()
{
  auto start = high_resolution_clock::now(); 
	kush_gupta();
    int t;
    cin>>t;
    while(t--)
    {
        int k,l,m,n,d;
        cin>>k>>l>>m>>n>>d;
        int count=0;
        for(int i=1;i<=d;i++)
        {
            if(i%k==0 || i%l==0 || i%m==0 || i%n==0)
            count++;
        }
        cout<<count<<endl;
    }
    auto stop = high_resolution_clock::now(); 
        auto duration = duration_cast<microseconds>(stop - start); 

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 

}

