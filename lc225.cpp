class MyStack {
public:
    queue<int> que;
    MyStack() {
        
    }
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        int sz = que.size();
        while (sz-- > 1) que.push(que.front()), que.pop();
        int cur = que.front();
        que.pop();
        return cur;
    }
    
    int top() {
        int sz = que.size();
        while (sz-- > 1) que.push(que.front()), que.pop();
        int cur = que.front();
        que.pop();
        que.push(cur);
        return cur;
        
    }
    
    bool empty() {
        return que.empty();
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
