class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
      vector<pair<int,int>> indexMap;
      int n = positions.size();
      for (int i = 0; i < n; i++) {
        indexMap.push_back({positions[i],i});
      }
      sort(indexMap.begin(), indexMap.end());


      stack<int> st;
      for (auto& [pos, idx] : indexMap) {
        if (directions[idx] == 'R') {
          st.push(idx);
          continue;
        } 
        while (!st.empty() && directions[st.top()] == 'R' && healths[idx] > 0) {
          if (healths[st.top()] > healths[idx]) {
            healths[idx] = 0;
            healths[st.top()]--;
          } else if (healths[st.top()] == healths[idx]) {
            healths[idx] = 0;
            healths[st.top()] = 0;
            st.pop();
          } else {
            healths[st.top()] = 0;
            st.pop();
            healths[idx]--;
          }
        }
        if (healths[idx] > 0) {
          st.push(idx);
        }
      }

      vector<int> res;
      for (int& num : healths) {
        if (num == 0) {
          continue;
        }
        res.push_back(num);
      }

      return res;
    }

};

/*
1 2 3 6 8
1 1 1 1 1
1. idx transfer to order by posistion
2. transfer result back to original order



if i is L and R in stack > collosion
if L and stack empty() or L in stack
ir R push


stack store the idx of array
*/