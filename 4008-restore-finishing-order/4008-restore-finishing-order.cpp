class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
      unordered_set<int> friendSet(friends.begin(),friends.end());
      vector<int> res;
      for (auto& id : order) {
        if (friendSet.find(id) != friendSet.end()) {
          res.push_back(id);
        }
      }
      return res;
    }
};