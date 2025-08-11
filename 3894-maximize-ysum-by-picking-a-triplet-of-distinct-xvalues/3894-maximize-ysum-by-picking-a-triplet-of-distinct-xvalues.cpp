class Solution {
public:
    // int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
    //   unordered_map<int,vector<int>> mp;
    //   for (int i = 0; i < y.size(); ++i) {
    //     mp[y[i]].push_back(i);
    //   }
    //   sort(y.rbegin(), y.rend());
    //   set<int> choseSet;
    //   int count = 0;
    //   int res = 0;
    //   int index = 0;
    //   while (index < y.size() && count < 3) {
    //     if (choseSet.find(x[mp[y[index]].back()]) == choseSet.end()) {
    //       cout <<  y[index] << " ";
    //       res += y[index];
    //       count++;
    //       choseSet.insert(x[mp[y[index]].back()]);
    //       mp[y[index]].pop_back();
    //     } else {
    //       mp[y[index]].pop_back();
    //     }
    //     index++;
    //   }
    //   return count == 3 ? res : -1;
    // }

    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
      vector<int> z(3,-1); 
      for(int i = 0; i < 3; i++) {
        int val = INT_MIN;
        for(int j = 0; j< y.size(); j++) {
          if (y[j] > val) {
            int k = i - 1;
            bool notFit = false;
            while (k >= 0) {
              if (j == z[k] || x[j] == x[z[k]]) {
                notFit = true;
              }
              k--;
            }
            if (notFit) continue;
            z[i] = j;
            val = y[j];
          }
        }
        if (z[i] == -1) break;
      }
      
      return z[2] == -1 ? -1 : y[z[0]] + y[z[1]] + y[z[2]]; 
    }
};


/*
  x is the set vectir of y


  10 10 10 9

*/