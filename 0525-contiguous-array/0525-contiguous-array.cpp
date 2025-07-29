class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
      int count = 0;
      unordered_map<int,int> countMap;
      countMap[0] = -1;
      int res = 0;
      for (int i = 0; i < nums.size(); ++i) {
        count += nums[i] == 1 ? 1 : -1;
        if (countMap.find(count) == countMap.end()) {
          countMap[count] = i;
        } else {
          res = max(res, i - countMap[count]);
        }
      }

      return res;
    }
};

/*
0   0   1   1   1   0   1   0   1
-1 -2  -1   0   1   0   1   0  

*/