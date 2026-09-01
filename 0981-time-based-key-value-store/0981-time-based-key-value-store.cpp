class TimeMap {
public:
  TimeMap() {
    
  }
  
  void set(string key, string value, int timestamp) {
    if (key_bucket.find(key) == key_bucket.end()) {
      key_bucket[key] = map<int,string>();
    }
    key_bucket[key].insert({timestamp, value});
  }
  
  string get(string key, int timestamp) {
    if (key_bucket.find(key) == key_bucket.end()) {
      return "";
    }
    map<int, string> &tmp = key_bucket[key];
    auto it = tmp.upper_bound(timestamp);
    if (it == tmp.begin()) {
      return "";
    }
    return  (--it)->second;
  }
private:
  unordered_map<string,map<int,string>> key_bucket;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */