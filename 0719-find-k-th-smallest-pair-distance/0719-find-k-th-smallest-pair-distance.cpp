class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> bucket(maxVal+1,0);


        for(int i = 0; i < n-1; ++i) {
          for(int j = i+1;j <n; ++j) {
            int dist = abs(nums[i] - nums[j]);
            bucket[dist]++;
          }
        }
        int i = 0;
        int count = 0;
        while(i <= maxVal && count < k) {
          count += bucket[i];
          i++;
        }
        return i-1;
    }
};



/*
pair of any two element
sort the array

priority queue 
give any adjecnt two pair element 
pop if queue size over k

binary Search
O(n log n)

bucket Sort


Question
* Is the num duplicate?
* Num range?

*/