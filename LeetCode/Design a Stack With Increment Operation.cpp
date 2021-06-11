class CustomStack {
public:
    vector <int> stack;
    vector <int> inc;
    int curr;
    CustomStack(int maxSize) {
        stack.resize(maxSize+1);
        inc.resize(maxSize+1,0);
        stack[0]=-1;
        curr=0;
    }
    
    void push(int x) {
        if (curr<stack.size()-1){
            stack[++curr]=x;
        }
    }
    
    int pop() {
        if (curr==0){
            return -1;
        }
        int res=stack[curr]+inc[curr];
        inc[curr-1]+=inc[curr];
        inc[curr]=0;
        curr--;
        return res;
    }
    
    void increment(int k, int val) {
        // for (int j=1;j<=min(k,curr);j++){
        //     stack[j]+=val;
        // }
        if (curr>0)
            inc[min(k,curr)]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */