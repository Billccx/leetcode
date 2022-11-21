class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int p=0,q=0;
        int pl=pushed.size(),ql=popped.size();
        while(p<pl && q<ql){
            if(s.empty()||s.top()!=popped[q]){
                s.emplace(pushed[p]);
                p++;
            }
            else if(s.top()==popped[q]){
                q++;
                s.pop();
            }
        }
        while(!s.empty() && s.top()==popped[q]){
            s.pop();
            q++;
        }

        if(p==pl && q==ql) return true;
        else return false;
    }
};

/*
直接进行模拟，如果压入栈的顶端数组不等于当前q指针所指向的弹出数字，则继续压入
不要忘记p指针到头后，需要用while而不是if不断弹出验证popped的序列
如果是合法的，最后两个指针都会指向末尾
*/