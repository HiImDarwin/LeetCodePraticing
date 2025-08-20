class RandomizedCollection {
    unordered_map<int,unordered_set<int>> numToIdx;
    vector<int> nums;
public:
    RandomizedCollection() {
      srand(time(NULL));
    }
    
    bool insert(int val) {
      bool notfound = (numToIdx.find(val) == numToIdx.end());
      nums.push_back(val);
      numToIdx[val].insert(nums.size() - 1);
      return notfound;
    }
    
    bool remove(int val) {
      if (numToIdx.find(val) == numToIdx.end()) {
        return false;
      }
      int lastVal = nums.back();
      int idx = *numToIdx[val].begin();
      if (idx == nums.size() - 1) {
        numToIdx[val].erase(idx);
      } else {
        swap(nums[idx], nums.back());
        numToIdx[val].erase(idx);
        numToIdx[nums[idx]].erase(nums.size()-1);
        numToIdx[nums[idx]].insert(idx);
      }
      nums.pop_back();

      if (numToIdx[val].empty()) {
        numToIdx.erase(val);
      }
      return true;
    }
    
    int getRandom() {
      int n = nums.size();
      int idx = rand()%n;
      return nums[idx];   
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */