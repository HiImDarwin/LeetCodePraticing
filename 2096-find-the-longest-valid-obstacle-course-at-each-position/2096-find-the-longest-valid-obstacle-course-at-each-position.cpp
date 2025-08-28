class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
      vector<int> piles;
      vector<int> res;

      for (auto& height : obstacles) {
        int idx = upper_bound(piles.begin(), piles.end(), height) - piles.begin();
        res.push_back(idx + 1);
        
        if (idx == piles.size()) {
          piles.push_back(height);
        } else {
          piles[idx] = height;
        }
      }

      return res;
    }


};





/*

 1 1 2 2 4 5 7

 2,2,1

 2 1
 2


*/