class Solution {
public:
    // long long maxTotal(vector<int>& value, vector<int>& limit) {
    //   int n = value.size();
    //   vector<priority_queue<int>> pqVec(n+1);
    //   vector<int> activeRecord(n+1,0);
    //   for (int i = 0; i < n; i++) {
    //     pqVec[limit[i]].push(value[i]);
    //   }
    //   int currentlyActive = 0;
    //   long long total = 0;

    //   for (int i = 0,j = 0; i <= n; i++) {
    //     //delete currentlyActive

    //     // add Node
    //     while(!pqVec[i].empty() && currentlyActive < i) {
    //       total += pqVec[i].top();
    //       pqVec[i].pop();
    //       currentlyActive++;
    //       activeRecord[i]++;
    //       while (j < i && currentlyActive > j) {
    //         currentlyActive -= activeRecord[j];
    //         j++;
    //       } 
    //     }
    //     if (currentlyActive == i) {
    //       currentlyActive -= activeRecord[i];
    //       activeRecord[i] = 0;
    //     }
    //   }
    //   return total;
    // }

    long long maxTotal(vector<int>& value, vector<int>& limit) {
      int n = value.size();
      unordered_map<int,vector<int>> mp;
      for (int i = 0; i < n; i++) {
        mp[limit[i]].push_back(value[i]);
      }
      int totalCount = 0;
      long long res = 0;
      for (auto& [key, valVec] : mp) {
        int limit = key;
        sort(valVec.rbegin(),valVec.rend());
        int take = min(limit, (int)valVec.size());
        for (int i = 0; i < take; i++) {
          res += valVec[i];
        }
      }
      return res;
    
    
    }
};

/*
number of currently active elements must be strictly less than limit[i]
total activation value


[2,1,3]
[3,5,8]
                    
 
*/