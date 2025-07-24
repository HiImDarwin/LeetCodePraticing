class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
      int n = status.size();
      unordered_set<int> boxWithoutKey;
      queue<int> processBox;
      int res = 0;

      for (int box : initialBoxes) {
        if(status[box] == 1) {
          processBox.push(box);
        } else {
          boxWithoutKey.insert(box);
        }
      }

      while (!processBox.empty()) {
        int box = processBox.front();
        processBox.pop();
        res += candies[box];
        // handle key
        for (int key : keys[box]) {
          status[key] = 1;
          if (boxWithoutKey.find(key) != boxWithoutKey.end()) {
            processBox.push(key);
            boxWithoutKey.erase(key);
          }
        }

        // handle containedBoxes in the box
        for (int containedBox : containedBoxes[box]) {
          if(status[containedBox] == 1) {
            processBox.push(containedBox);
          } else {
            boxWithoutKey.insert(containedBox);
          }
        }
      }
      
      return res;
    }
};