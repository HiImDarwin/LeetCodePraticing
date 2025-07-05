class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
      if (p == 0) return 0;
      sort(nums.begin(), nums.end());
      int left = 0, right = nums[nums.size()-1] - nums[0];
      while(left < right) {
        int mid = left + (right - left) / 2;
        if(enoughPair(nums, p, mid)) {
          right = mid;
        } else {
          left = mid + 1;
        }
      }
      return left;
    }

    bool enoughPair(vector<int>& nums, int p, int diff) {
      int count = 0;
      for(int i = 0; i <nums.size()-1; i++) {
        if(nums[i+1] - nums[i] <= diff){
          count++;
          i = i+1;
        }
      }
      return count >= p;
    }

};

/*
find p pairs of indice {a,b}
no index appears more than once

if we brute force find the pair
it gona be O(n^2)



Qusetion:
will the value duplicate? yes



*/