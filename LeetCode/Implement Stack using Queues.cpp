class MyStack {
public:
    /** Initialize your data structure here. */
    queue <int> q;
    MyStack() {
        // q.clear();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        int s=q.size();
        for (int i=1;i<s;i++){
            int ele=q.front();
            q.pop();
            q.push(ele);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ele=q.front();
        q.pop();
        return ele;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */