class BrowserHistory {
public:
    vector <string> v;
    int curr=-1;
    BrowserHistory(string homepage) {
        v.push_back(homepage);
        curr++;
    }
    
    void visit(string url) {
        while (curr!=v.size()-1){
            v.pop_back();
        }
        v.push_back(url);
        curr++;
    }
    
    string back(int steps) {
        if (curr<steps){
            curr=0;
        }
        else{
            curr-=steps;
        }
        return v[curr];
    }
    
    string forward(int steps) {
        if (steps+curr>=v.size()){
            curr=v.size()-1;
        }
        else{
            curr+=steps;
        }
        return v[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */