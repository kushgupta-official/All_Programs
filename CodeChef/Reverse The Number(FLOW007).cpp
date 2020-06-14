#include <iostream>
#include <vector>
using namespace std;

int rev(int num){
    int sol=0;
    while(num>0){
        sol=sol*10+(num%10);
        num/=10;
    }
    return sol;
}

int main() {
    std::vector<int> solution;
    int test_cases;
    cin>>test_cases;
    
    for (int i=0;i<test_cases;i++){
        int x;
        cin>>x;
        solution.push_back(rev(x));
    }
    
    for (int i=0;i<test_cases;i++){
        cout<<solution[i]<<endl;
    }
	return 0;
}
