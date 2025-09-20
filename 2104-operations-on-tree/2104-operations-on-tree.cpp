class LockingTree {

public:
    LockingTree(vector<int>& parent) {
      int n = parent.size();
      this->parent_ = parent;
      descendant_.resize(n);
      for (int i = 1; i < n; i++) {
        descendant_[parent[i]].push_back(i);
      }
      BIT_.resize(n);
    }
    
    bool lock(int num, int user) {
      if(BIT_[num].second != 0) {
        return false;
      }
      BIT_[num].second = user;
      editLockAmount_(num, 1);
      return true;
    }
    
    bool unlock(int num, int user) {
      if (BIT_[num].second != user) {
        return false;
      }
      BIT_[num].second = 0;
      editLockAmount_(num, -1);
      return true;
    }
    
    bool upgrade(int num, int user) {
      if (BIT_[num].second != 0 || BIT_[num].first == 0) {
        return false;
      }
      if (chackAncestorLock_(num)) {
        return false;
      }
      int amount = BIT_[num].first;
      editLockAmount_(num, -amount);
      unlockDescendant_(num);
      lock(num, user);
      return true;
    }
  private:
    void editLockAmount_(int num, int amount) {
      BIT_[num].first += amount;
      if (parent_[num] != -1) {
        editLockAmount_(parent_[num], amount);
      }
    }
    bool chackAncestorLock_(int num) {
      if (parent_[num] == -1) {
        return BIT_[num].second != 0;
      }
      return BIT_[num].second != 0 || chackAncestorLock_(parent_[num]);
    }
    void unlockDescendant_(int num) {
      BIT_[num].first = 0;
      BIT_[num].second = 0;
      for (const auto& des :descendant_[num]) {
        unlockDescendant_(des);
      }
    }
  private:
    vector<int> parent_;
    vector<vector<int>> descendant_;
    vector<pair<int,int>> BIT_;
};


/*

we have a tree structure
lock O(log n)
 * if node is unlock

unlock O(log n)
 * by same user
 * by upgrade

upgrade O(log n)
 * node is unlock
 * at least 1 lock descendant
 * no lock ancestors (can it be optimal?)
  * trace the path
 * unlock descendant (how to do it fast?)
  * brute force
    * iterate all descendent
  * can it done with lazy?
  * when we try to lock we go through all ancesstor check unlockDescendFlag 
    (Wrong. We need all branch been done)
   * all false > add 1
   * some one true > unlock along the backtrace path

binary index tree
if lock then value of node is 1
lock along the path to the parent

*/

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */