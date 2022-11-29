class MaxQueue {
public:
    queue<int> q;
    deque<int> dq;
    MaxQueue() {
        
    }
    
    int max_value() {
        if(!q.empty()) return dq.front();
        else return -1;
    }
    
    void push_back(int value) {
        q.emplace(value);
        while(!dq.empty()&& dq.back()<value) dq.pop_back();
        dq.push_back(value);
    }
    
    int pop_front() {
        int ret;
        if(!q.empty()){
            ret=q.front();
            q.pop();
            if(dq.front()==ret) dq.pop_front();
        }
        else ret=-1;
        return ret;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

/*
思路
单调队列
同：滑动窗口的最大值/滑动窗口的最大值_双端队列.cpp
*/