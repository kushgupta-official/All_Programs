# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define vi std::vector<int>
# define vll std::vector<ll>
# define w(x) ll x=0; cin>>x; while(x--)
# define endl '\n'

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

string calculate_bit_score(ll num){
  ll maximum=-1,minimum=10;
  while(num!=0){
    ll dig=num%10;
    num/=10;
    maximum=max(maximum,dig);
    minimum=min(minimum,dig);
  }
  ll bit_score=(maximum*11) + (minimum*7);
  stringstream ss;
  ss<<bit_score;
  string toreturn="";
  if (bit_score<100){
    ss>>toreturn;
    return toreturn;
  }
  else{
    ss>>toreturn;
    return toreturn.substr(1,2);
  }
}

int main()
{
	kush_gupta();
	ll n=0;
  cin>>n;
  std::vector<string> bit_scores;
  while(n--){
    ll num=0;
    cin>>num;
    string bit_score=calculate_bit_score(num);
    bit_scores.push_back(bit_score);
  }
  /*bit_scores[0]="99";
  bit_scores[2]="99";
  bit_scores[4]="99";
    bit_scores[6]="99";*/


 for (ll i=0;i<bit_scores.size();i++){
    cout<<bit_scores[i]<<endl;
  }
  /*
    2. Rules for making pairs from above calculated bit scores

Condition for making pairs are

Both bit scores should be in either odd position or even position to be eligible to form a pair.

Pairs can be only made if most significant digit are same and at most two pair can be made for a given significant digit.
  */
  ll result=0;
  std::vector<ll> pairs_even(10,0);
  std::vector<ll> pairs_odd(10,0);
  for (ll i=0;i<bit_scores.size();i++){
    stringstream ss;
    ss<<bit_scores[i][0];
    ll msd=-1;
    ss>>msd;
    cout<<msd<<endl;
    if ((i+1)%2==1){
      pairs_odd[msd]++;
      if (pairs_odd[msd]>1 && pairs_odd[msd]<4){
        result++;
      }
    }
    else{
      pairs_even[msd]++;
      if (pairs_even[msd]>1 && pairs_even[msd]<4){
        result++;
      }
    }
  }
  for (ll i=0;i<10;i++){
    cout<<i<<"\t"<<pairs_odd[i]<<"\t"<<pairs_even[i]<<endl;
  }
  cout<<result<<endl;
	return 0;
}