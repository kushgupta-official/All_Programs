#include <iostream>

using namespace std;
int main() 
{
    int n;
    cin>>n;
    int p[n+1];
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        p[a]=i;
    }
    for(int i=1;i<=n;i++)cout<<p[p[i]]<<endl;
    return 0;
}