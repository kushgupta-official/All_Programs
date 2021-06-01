# include <bits/stdc++.h>
# include <ext/pb_ds/assoc_container.hpp> 
# include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

# define ll long long
# define ld long double
# define loop(i,a,b) for(ll i=a;i<b;i++)
# define vi vector<int>
# define vll vector<ll>
# define vvl vector<vector <ll> >
# define vp vector <pair <ll,ll> >
# define vpp vector <pair <pair <ll,ll>,ll> >
# define pp pair <pair <ll,ll>,ll>
# define pb(x) push_back(x)
# define w(x) ll x=0; cin>>x; while(x--)
# define endl '\n'
# define mid(l,r) l+(r-l)/2
# define fi first
# define se second

template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

int res,temp;
    vector <vector <bool> > visited;
    vector <pair <int,int> > directions;
    void dfs(vector<vector<int>>& grid,int i,int j){
        // if (i<0 or i>=grid.size() or j<0 or j>=grid[0].size()){
        //     return; 
        // }
        // if (grid[i][j]==0){
        //     return;
        // }
        if (visited[i][j]){
            return;
        }
        visited[i][j]=1;
        temp++;
        for (int k=0;k<4;k++){
        	int x=i+directions[k].first;
        	int y=j+directions[k].second;
        	cout<<x<<" "<<y<<endl;
        	// if (!(x<0 or x>=grid.size() or y<0 or y>=grid[0].size())){
        	// 	if (grid[x][y]==1)
         //    		dfs(grid,x,y);
         //    }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        res=INT_MIN;
        directions={ {1,0} , {-1,0} , {0,1} , {0,-1} };
        visited.resize(grid.size());
        for (int i=0;i<grid.size();i++){
            visited[i].resize(grid[0].size(),false);
        }
        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
            	cout<<visited[i][j]<<" ";
            }
            cout<<endl;
        }
        
        // cout<<"hi";
        // for (int i=0;i<grid.size();i++){
        //     for (int j=0;j<grid[0].size();j++){
        //         if (grid[i][j]==1 && !visited[i][j]){
        //             temp=0;
        //             dfs(grid,i,j);
        //             res=max(res,temp);
        //         }
        //     }
        // }
        return res;
    }

void kush_gupta_solves(){
	int x=0,y=0;
	cin>>x>>y;
	vector <vector <int> > grid;
	grid.resize(x);
	loop(i,0,x){
		grid[i].resize(y);
		loop(j,0,y){
			cin>>grid[i][j];
		}
	}
	cout<<maxAreaOfIsland(grid);
}

int main()
{
	#ifndef ONLINE_JUDGE
		auto __start = chrono::high_resolution_clock::now(); 
		freopen("input.txt", "r", stdin) ;
  		freopen("output.txt", "w", stdout) ;
	#endif

	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	kush_gupta_solves();

	#ifndef ONLINE_JUDGE
		auto __end = chrono::high_resolution_clock::now(); 
		double __time_taken=chrono::duration_cast<chrono::nanoseconds>(__end - __start).count(); 
		__time_taken *= 1e-9; 
		cout<<"\nTime Taken : "<<fixed<< __time_taken << setprecision(9); 
		cout << " sec" << endl;
	#endif

	return 0;
}