class CQueue {
public:
    stack<int> s1,s2;
    CQueue() {

    }
    
    void appendTail(int value) {
        s2.push(value);
    }
    
    int deleteHead() {
        int ans;
        if(s1.empty() && s2.empty()) ans=-1;
        else if(!s1.empty()){
            ans=s1.top();
            s1.pop();
        }
        else{
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
            ans=s1.top();
            s1.pop();
        }
        return ans;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */