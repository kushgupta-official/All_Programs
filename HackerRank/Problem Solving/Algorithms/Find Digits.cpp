#include <bits/stdc++.h>

using namespace std;

int findDigits(int n) {
    int toReturn=0;
    int temp=n;
    while(temp!=0){
        int dig=temp%10;
        if (dig!=0 and n%dig==0){
            toReturn++;
        }
        temp/=10;
    }
    return toReturn;
}

int main()
{
   int t;
   cin>>t;
   while(t--){
       int n;
       cin>>n;
       cout<<findDigits(n)<<endl;
   } 
}
