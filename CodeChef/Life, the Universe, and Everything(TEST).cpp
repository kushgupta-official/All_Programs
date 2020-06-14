# include <iostream>
# include <vector>

using namespace std;


int main(){
    size_t x=0;
    std::vector<size_t> res;

    while(x!=42){
        cin>>x;
        res.push_back(x);
    }
    res.pop_back();
    for (int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
}
