class MinStack {
private:
  vector<int> st;
  vector<int> minSt;
public:
    MinStack() {
    }
    
    void push(int val) {
        st.push_back(val);
        if(minSt.empty() || val <= minSt.back()) {
          minSt.push_back(val);
        }
    }
    
    void pop() {
      if(st.empty()) {
        throw runtime_error("pop when stack is empty");
      }
      if(st.back() == minSt.back()){
        minSt.pop_back();
      }
      st.pop_back();
    }
    
    int top() {
      if(st.empty()) {
        throw runtime_error("top operation on an empty stack");
      }
      return st.back();
    }
    
    int getMin() {
      if(minSt.empty()) {
        throw runtime_error("pop when stack is empty");
      }
        return minSt.back();
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