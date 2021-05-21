#include <bits/stdc++.h>
#define ll long long int
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'kaprekarNumbers' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER p
 *  2. INTEGER q
 */

void kaprekarNumbers(ll p, ll q) {
    ll res=0;
    for (ll i=p;i<=q;i++){
        ll sq=i*i;
        ll temp=i;
        ll digs=0;
        while(temp!=0){
            digs++;
            temp/=10;
        }   
        temp=0;
        for (ll j=0;j<digs;j++){
            temp+=(sq%10)*pow(10,j);
            sq/=10;
        }
        if (temp+sq==i){
            cout<<i<<" ";
            res++;
        }
    }
    if (res==0){
        cout<<"INVALID RANGE";
    }
}

int main()
{
    string p_temp;
    getline(cin, p_temp);

    ll p = stoi(ltrim(rtrim(p_temp)));

    string q_temp;
    getline(cin, q_temp);

    ll q = stoi(ltrim(rtrim(q_temp)));

    kaprekarNumbers(p, q);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
