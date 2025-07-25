/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
  vector<int> val;
  int index;
  void getVal(NestedInteger& nestedList) {
    if (nestedList.isInteger()) {
      val.push_back(nestedList.getInteger());
    } else {
      for(auto &x :nestedList.getList()) {
        getVal(x);
      }
    }
  }

public:

    NestedIterator(vector<NestedInteger> &nestedList) {
      for(auto nl : nestedList) {
       getVal(nl);
      }
      index = 0;
    }
    
    int next() {
      return val[index++];
    }
    
    bool hasNext() {
        return index < val.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */