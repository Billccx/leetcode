class StockSpanner {
public:
    stack<pair<int,int>> s;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int sum=1;
        while(!s.empty() && s.top().first<=price){
            sum+=s.top().second;
            s.pop();
        }
        s.push(make_pair(price,sum));
        return sum;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */