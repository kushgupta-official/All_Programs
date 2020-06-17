# include <bits/stdc++.h>

using namespace std;
# define ll long long int

map<char,int> precedence;


int main(){
	//precedence.insert(pair<char,int>(',',3));
	precedence['*']=0;
	precedence['/']=0;
	precedence['+']=1;
	precedence['-']=1;
	precedence['^']=2;
	int test_cases=0;
	cin>>test_cases;
	while(test_cases--){
		int n=0;
		cin>>n;
		string s="";
		cin>>s;
		s='('+s+')';
		string result="";
		stack <char>st;
		for (int i=0;i!=s.size();i++){
			if (!st.empty()){
				stack <char>temp=st;
				string t="";
				while(!temp.empty()){
					t=temp.top()+t;
					temp.pop();
				}
				cout<<s[i]<<"\t"<<t<<"\t"<<result<<endl;
			}
			switch(s[i]){
				case '(':	st.push('(');
							break;
				case ')':	while(st.top()!='('){
								char ch=st.top();
								result=result+ch;
								st.pop();
							}
							st.pop();
							break;
				case '+':	if (st.top()!='(' && precedence[st.top()]>precedence['+']){
								result=result+st.top();
							}
							st.push('+');
							break;
				case '-':	if (st.top()!='(' && precedence[st.top()]>precedence['-']){
								result=result+st.top();
							}
							st.push('-');
							break;
				case '*':	st.push('*');
							break;
				case '/':	st.push('/');
							break;
				case '^':	if (st.top()!='(' && precedence[st.top()]>precedence['^']){
								result=result+st.top();
							}
							st.push('^');
							break;
				default:	result=result+s[i];
			}
		}
		cout<<result<<endl;
	}
	return 0;
}