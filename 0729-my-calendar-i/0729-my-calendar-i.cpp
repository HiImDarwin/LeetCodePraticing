class MyCalendar {
  set<pair<int,int>> Set;
public:
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {

      auto pos = Set.lower_bound({startTime, endTime});
      if(pos != Set.end() && pos->first < endTime) return false;
      if(pos != Set.begin()) {
        auto pre = prev(pos,1); 
        if(pre->second > startTime) return false;
      }
      Set.insert(make_pair(startTime, endTime));
      return true;
    }
};
/*
startTime < other's endTime than is not good
Set with pair
*/











/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */