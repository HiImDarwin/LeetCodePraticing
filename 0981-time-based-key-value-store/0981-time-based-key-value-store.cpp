class TimeMap {
public:
  TimeMap() {
    
  }
  
  void set(string key, string value, int timestamp) {
    if (key_bucket.find(key) == key_bucket.end()) {
      key_bucket[key] = vector<pair<int,string>>();
    }
    key_bucket[key].push_back({timestamp, value});
  }
  
  string get(string key, int timestamp) {
    if (key_bucket.find(key) == key_bucket.end()) {
      return "";
    }
    vector<pair<int, string>> &tmp = key_bucket[key];
    int left = 0, right = tmp.size() - 1;
    while (left < right) {
      int mid = right - (right - left) / 2;
      if (tmp[mid].first > timestamp) {
        right = mid - 1;
      } else {
        left = mid;
      }
    }
    return tmp[left].first > timestamp ? "" : tmp[left].second;
  }
private:
  unordered_map<string,vector<pair<int,string>>> key_bucket;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */