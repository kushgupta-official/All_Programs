# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define vi std::vector<int>
# define vll std::vector<ll>

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  /*#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif*/
}

ll bs(ll a, ll b, ll y, int cord){
  string str="";
  ll res=0;
  while(a<=b){
    ll mid=(a+b)/2;
    if (cord==0)
      cout<<"? "<<mid<<" "<<y<<endl;
    else
      cout<<"? "<<y<<" "<<mid<<endl;
    fflush(stdout);
    cin>>str;
    if (str=="YES"){
      res=mid;
      a=mid+1;
    }
    else{
      b=mid-1;
    }
  }
  return res;
}

int main()
{
	//kush_gupta();
  ll area=0;
	ll square_corner=0,triangle_base=0,triangle_height=0;
  ll y=0;
  square_corner=bs(1,1000,0,0);  
  //cout<<"square_corner = "<<square_corner<<endl;
  triangle_base=bs(square_corner,1000,2 * square_corner,0);
  //cout<<"triangle_base = "<<triangle_base<<endl;
  triangle_height=bs(2*square_corner,1000,0,1);
  //cout<<"triangle_height = "<<triangle_height<<endl;
  area=pow(2*square_corner,2)+(0.5*(triangle_base*2)*(triangle_height-(2*square_corner)));
  //cout<<"area = "<<area<<endl;
  cout<<"! "<<area<<endl;
	return 0;
}