class MinStack {
public:
    /** initialize your data structure here. */
    stack <int> Stack,minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        Stack.push(val);
        if (!minStack.empty() and minStack.top()<val){
            minStack.push(minStack.top());
        }
        else{
            minStack.push(val);
        }
    }
    
    void pop() {
        Stack.pop();
        minStack.pop();
    }
    
    int top() {
        return Stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */