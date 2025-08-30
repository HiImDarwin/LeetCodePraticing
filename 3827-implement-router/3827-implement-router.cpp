class Router {
public:
    Router(int memoryLimit) : memory_limit_(memoryLimit)  {
    }
    
    bool addPacket(int source, int destination, int timestamp) {
      pair<int,pair<int,int>> record = {destination, {timestamp, source}};
      if (packetRecord.find(record) != packetRecord.end()) {
        return false;
      }

      if (qu.size() == memory_limit_) {
        pair<int,pair<int,int>> oldRecord = qu.front();
        qu.pop();
        packetRecord.erase(oldRecord);
        lazyDelete[oldRecord.first]++;
        if (timeStampRecord[oldRecord.first].size() == lazyDelete[oldRecord.first]) {
          timeStampRecord.erase(oldRecord.first);
          lazyDelete.erase(oldRecord.first);
        }
      }
      qu.push(record);
      timeStampRecord[destination].push_back(timestamp);
      packetRecord.insert(record);
      return true;
    }
    
    vector<int> forwardPacket() {
      if (qu.empty()) {
        return {};
      }
      
      pair<int,pair<int,int>> record = qu.front();
      qu.pop();
      packetRecord.erase(record);
      lazyDelete[record.first]++;
      if (timeStampRecord[record.first].size() == lazyDelete[record.first]) {
        timeStampRecord.erase(record.first);
        lazyDelete.erase(record.first);
      }

      vector<int> res = {record.second.second, record.first, record.second.first};
      return res;
    }
    
    int getCount(int destination, int startTime, int endTime) {
      auto it1 = lower_bound(timeStampRecord[destination].begin() + lazyDelete[destination],
                             timeStampRecord[destination].end(),
                             startTime);
      auto it2 = upper_bound(timeStampRecord[destination].begin() + lazyDelete[destination],
                             timeStampRecord[destination].end(),
                             endTime);
      return it2 - it1;
    }

private:
    int memory_limit_;
    queue<pair<int,pair<int,int>>> qu;
    set<pair<int,pair<int,int>>> packetRecord;
    unordered_map<int,vector<int>> timeStampRecord;
    unordered_map<int,int> lazyDelete;
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */