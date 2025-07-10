class ExamRoom {
    set<int> seats;
    int capacity;
public:
    ExamRoom(int n) {
        capacity = n;
    }
    
    int seat() {
      int dist = 0;
      int curr = 0;
      int pre = 0;
      if(!seats.empty()) {
        auto it = seats.begin();
        if(*it != 0) 
          dist = *it;
        else 
          it++;
        while(it != seats.end()) {
          if(dist < (*it - pre) / 2) {
            dist = (*it - pre) / 2;
            curr = pre + (*it - pre) / 2;
          }
          pre = *it;
          it++;
        }
        if(dist < capacity-1 - pre){
          curr = capacity-1;
        }
      }

      seats.insert(curr);
      return curr;
    }
    
    void leave(int p) {
        seats.erase(p);
    }
};





/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */