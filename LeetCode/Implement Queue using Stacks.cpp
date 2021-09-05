class MyQueue {
public:
    /** Initialize your data structure here. */
    stack <int> s1,s2;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (s2.empty()){
            while(!s1.empty()){
                int ele=s1.top();
                s1.pop();
                s2.push(ele);
            }
        }
        int ele=s2.top();
        s2.pop();
        return ele;
    }
    
    /** Get the front element. */
    int peek() {
        if (s2.empty()){
            while(!s1.empty()){
                int ele=s1.top();
                s1.pop();
                s2.push(ele);
            }
        }
        int ele=s2.top();
        return ele;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        // cout<<s1.size()<<endl<<s2.size()<<endl;
        return !(s1.size()||s2.size());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */