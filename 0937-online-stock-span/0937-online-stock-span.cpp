class StockSpanner {
public:
    StockSpanner() {
    }
    
    int next(int price) {
        record.push_back(price);
        int n = record.size()-1;
        // monotonic decrease
        while(!st.empty() && price>=record[st.top()]) {
            st.pop();
        }
        int old = st.empty() ? -1 :st.top();
        st.push(n);
        return n-old;
    }
private:
    vector<int> record;
    stack<int> st;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */