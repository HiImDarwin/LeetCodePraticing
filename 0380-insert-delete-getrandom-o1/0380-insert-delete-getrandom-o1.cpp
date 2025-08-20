class RandomizedSet {
    unordered_map<int,int> numToIdx;
    vector<int> nums;
    int n;
public:
    RandomizedSet() {
      srand(time(NULL));
      n = 0;
    }
    
    bool insert(int val) {
      if (numToIdx.find(val) == numToIdx.end()) {
        numToIdx[val] = n;
        nums.push_back(val);
        n++;
        return true;
      }
      return false;
    }
    
    bool remove(int val) {
      if (numToIdx.find(val) == numToIdx.end()) {
        return false;
      }
      int idx = numToIdx[val];
      swap(nums[idx],nums.back());
      numToIdx[nums[idx]] = idx;
      nums.pop_back();
      numToIdx.erase(val);
      n--;
      return true;
    }
    
    int getRandom() {
      
      int idx = rand()%n;
      return nums[idx];   
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */