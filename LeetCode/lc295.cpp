class MedianFinder {
public:
    priority_queue<int> down;
    priority_queue<int, vector<int>, greater<int>> up;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (down.empty() || down.top() >= num)
        {
            down.push(num);
            if (down.size() > up.size() + 1)
            {
                up.push(down.top());
                down.pop();
            }
        }
        else
        {
            up.push(num);
            if (up.size() > down.size())
            {
                down.push(up.top());
                up.pop();
            }
        }
    }
    
    double findMedian() {
        if ((down.size() + up.size()) & 1) return down.top();
        return (down.top() + up.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */