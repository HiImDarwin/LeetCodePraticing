class LRUCache {
  struct Data {
    Data(int k, int v) {
      key = k;
      val = v;
      next = nullptr;
      prev = nullptr;
    }
    int key;
    int val;
    Data* next;
    Data* prev;
  };

  Data* head;
  Data* tail;
  int DataCount;
  int cap;
  unordered_map<int,Data*> mp;
public:
    LRUCache(int capacity) {
      cap = capacity;
      DataCount = 0;
      head = nullptr;
      tail = nullptr;
    }
    
    int get(int key) {
      if (mp.find(key) == mp.end()) {
        return -1;
      }
      // move node
      update(key,mp[key]->val);
      return mp[key]->val;
    }
    
    void put(int key, int value) {
      if (mp.find(key) != mp.end()) {
        update(key, value);
        return;
      }
      Data* newData = new Data(key, value);
      mp[key] = newData;
      if (DataCount < cap) {
        if (tail == nullptr) {
          tail = newData;
        }
        newData->prev = head;
        if (head != nullptr) {
          head->next = newData;
        }
        head = newData;
        DataCount++;
      } else {
        newData->prev = head;
        head->next = newData;
        head = newData;
        Data* oldData = tail;
        tail = tail->next;
        tail->prev = nullptr;
        mp.erase(oldData->key);
        delete oldData;
      }
    }
    // change value and move node
    void update(int key, int value) {
      Data* node = mp[key];
      node->val = value;
      if (node == head) {
        return;
      }
      if (node == tail) {
        tail = tail->next;
      }
      if (node->prev) {
        node->prev->next = node->next;
      }
      if (node->next) {
        node->next->prev = node->prev;
      }
      head->next = node;
      node->prev = head;
      node->next = nullptr;
      head = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


 /*
least recently used
time order

 a -> b -> c -> d->
 ^              ^
 |              |
 tail           head

 link list + unordered_map


 vector + lazy deletion

 */