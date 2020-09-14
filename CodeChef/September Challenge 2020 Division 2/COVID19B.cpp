#include<bits/stdc++.h>
#define ll long long 
#define OJ \
        freopen("input.txt","r",stdin); \
        freopen("output.txt","w",stdout);
using namespace std;
int mod=1000000007;
int main()
{
    //    OJ;
int T;
cin>>T;
while(T--)
{
        int n;
        cin>>n;
        int a[n];
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
                cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
                int b[n]={0};
                double meet[n]={0};
                b[i]=1;

                for(int j=i;j<n;j++)
                {
                  if(a[j]<a[i])
                  {
                          b[j]=1;
                          meet[j]=double(j-i)/double(a[i]-a[j]);

                  }
                }
                for(int j=i;j>=0;j--)
                {
                  if(a[j]>a[i])
                  {
                          b[j]=1;
                          meet[j]=double(i-j)/double(a[j]-a[i]);
                  }
                }
                for(int k=0;k<n;k++)
                {
                      if(b[k]==1&&k!=i)
                      {
                         for(int x=k+1;x<n;x++)
                         {
                                 if(a[k]>a[x])
                                 {
                                double temp=double(x-k)/double(a[k]-a[x]);
                                if(temp>=meet[k])
                                {
                                        b[x]=1;
                                        meet[x]=temp;
                                }
                                 }

                         }
                         for(int x=k-1;x>=0;x--)
                         {
                                 if(a[k]<a[x])
                                 {
                                double temp=double(k-x)/double(a[x]-a[k]);
                                if(temp>=meet[k])
                                {
                                        b[x]=1;
                                        meet[x]=temp;
                                }
                                 } 
                         }
                      }
                }
                 int temp=0;
           for(int m=0;m<n;m++)
           {
                  
                   if(b[m]==1)
                   {
                   temp++;
                   }

           }
           ans.push_back(temp);
        }
        sort(ans.begin(),ans.end());
        cout<<ans[0]<<" "<<ans[n-1]<<endl;
}        
}