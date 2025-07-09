class Solution {
public:
    int widestPairOfIndices(vector<int>& nums1, vector<int>& nums2) {
      vector<int> arr;
      for (int i = 0; i <nums1.size(); ++i) {
        arr.push_back(nums1[i] - nums2[i]);
      }
      unordered_map<int,int> Map;
      Map[0] = -1;
      
      int presum = 0;
      int res = 0;
      for(int i = 0; i < arr.size(); i++) {
        presum += arr[i];
        if (Map.find(presum) != Map.end())
          res = max(res, i - Map[presum]);
        else 
          Map[presum] = i;
      }
      return  res;
    }
};


/*
we want  
prefix1[j] - prfixp1[i] = prefix2[j] - prfixp2[i]

we want tha longest
if we use vector for prefix sum


for(length = n-1; length >0; length --){}
  for(int i =0; i+length < n; i++)



if we used unordere_map for prefix sum

[1 1 0 0 1 0 1]

[0 -1] [1 0] [2 3] [3 5] [4 6]
for range 0  -1 ~ -1
for range 1  -1 ~  0
for range 2   3 ~  1

[0 1 0 1 0 1 1]

[0 0] [1 2] [2 4] [3 5] [4 6]



question
1. is nums1 length equal nums2 length?
2. num range of nums1 and nums2  1~1e5 >> too big can't used vector 
  2.1 how do we apply optimal (On space or on time)
3. value range in nums1 and nums2


*/