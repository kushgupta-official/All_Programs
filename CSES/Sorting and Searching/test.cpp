#include <bits/stdc++.h>
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
    kush_gupta(); 
    int k;
cin>>k;
while(k!=0)
{
int flag=0;
string s,t;
cin>>s>>t;
int n=s.length();
int m=t.length();
for(int i=0,j=0;i<n,j<m; )
{
if(s[i]==t[j])
{
i++;
j++;
if(j==m&&i!=n)
{
  if(n>m)
  {
      flag=1;
    cout<<"NO";
  }
}
}
else
{
if(t[j]=='+' && s[i]=='-' && s[i+1]=='-')
{
s[i]='+';
i=i+2;
j=j+1;
}
else
{
flag=1;
cout<<"NO";
break;
}
}
}
if(flag==0)
{
cout<<"YES";
}
cout<<endl;
k--;
}

    
    return 0;
  }