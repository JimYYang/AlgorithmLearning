class MyCircularDeque {
public: 
    // 本题核心是tt - hh 代表状态数量（队列中有多少元素）
    // hh 是队头  tt是队尾前一个
    // get 函数很重要  + 1 - 1 的操作都需要
    vector<int> q;
    int hh = 0, tt = 0;
    MyCircularDeque(int k) {
        q = vector<int> (k + 1);
    }

    int get(int x){
        return (x + q.size()) % q.size();
    }
    
    bool insertFront(int value) {
        if(isFull())return false;

        hh = get(hh - 1);

        q[hh] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull())return false;
        q[tt] = value;
        tt = get(tt + 1);
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())return false;

        hh = get(hh + 1);
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())return false;

        tt = get(tt - 1);

        return true;
    }
    
    int getFront() {
        if(isEmpty())return -1;

        return q[hh];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return q[get(tt - 1)];
    }
    
    bool isEmpty() {
        return hh == tt;
    }
    
    bool isFull() {
        return tt == get(hh - 1);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
