class MinStack {
public:
    stack<int> stk;
    stack<int> min_ele;
    MinStack() {
        min_ele.push(INT_MAX);
    }
    
    void push(int val) {
        stk.push(val);
        min_ele.push(min(val, min_ele.top()));
    }
    
    void pop() {
        stk.pop();
        min_ele.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_ele.top();
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
