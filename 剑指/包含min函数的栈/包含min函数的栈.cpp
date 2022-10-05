class MinStack {
public:
    /** initialize your data structure here. */
    int minnum;
    stack<int> s,st;
    MinStack() {

    }
    
    void push(int x) {
        if(s.empty()) minnum=x;
        else if(x<minnum) minnum=x;
        s.push(x);
        st.push(minnum);
    }
    
    void pop() {
        s.pop();
        st.pop();
        if(!st.empty())minnum=st.top();
    }
    
    int top() {
        return s.top();
    }
    
    int min() {
        return st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */