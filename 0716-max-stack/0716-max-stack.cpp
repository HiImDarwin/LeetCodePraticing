class MaxStack {
    struct node {
      node(int num) {
        val = num;
        prev = nullptr;
        next = nullptr;
      }
      int val;
      node* prev;
      node* next;
    };

    node* head;
    priority_queue<pair<int,node*>> pq;
    unordered_set<node*> lazySet;
    
public:
    MaxStack() {
      head = new node(0);
    }
    
    void push(int x) {
      node* newNode = new node(x);
      if (head) {
        head->next = newNode;
        newNode->prev = head;
      }
      head = newNode;
      pq.push({x, newNode});
    }
    
    int pop() {
      int topVal = head->val;
      node* tmp = head;
      head = head->prev;
      if (head) {
        head->next =nullptr;
      }
      if (tmp == pq.top().second) {
        pq.pop();
        delete tmp;
      } else {
        lazySet.insert(tmp);
      }
      return topVal;      
    }
    
    int top() {
      return head->val;
    }
    
    int peekMax() {
      while (lazySet.find(pq.top().second) != lazySet.end()) {
        node* deleteNode = pq.top().second;
        pq.pop();
        delete deleteNode;
      }
      int maxVal = pq.top().first;
      return maxVal;
    }
    
    int popMax() {
      while (lazySet.find(pq.top().second) != lazySet.end()) {
        node* deleteNode = pq.top().second;
        pq.pop();
        delete deleteNode;
      }
      int maxVal = pq.top().first;
      node* tmp = pq.top().second;
      pq.pop();
      
      if (tmp == head) {
        head = head->prev;
      }
      if (tmp->next) {
        tmp->next->prev = tmp->prev;
      }
      if (tmp->prev) {
        tmp->prev->next = tmp->next;
      }
      return maxVal;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */


 /*

 link list
 x -> y -> z -> 


 priorityQueue<val, link list node>
 */