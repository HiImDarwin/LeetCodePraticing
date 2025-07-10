class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<long> Set;
        for(int j = 0; j <nums.size(); ++j) {
          if(j > indexDiff) Set.erase(Set.lower_bound(nums[j - indexDiff - 1]));

          auto pos = Set.lower_bound(nums[j] - valueDiff);
          if (pos != Set.end() && *pos <= nums[j] + valueDiff) 
            return true;

          Set.insert(nums[j]); 
        }
        return false;
    }
};





/*

XXXX | XXXXXXXXXX | XXXX
     | indexDiff  |   

sorted ->
window is size is indexDidd+1


固定一個 i 點是否可以高效找到一個 j
          
*/