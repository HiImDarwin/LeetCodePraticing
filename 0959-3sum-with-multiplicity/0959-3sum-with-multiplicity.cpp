class Solution {
public:
//     int threeSumMulti(vector<int>& nums, int target) {
//       int n = nums.size();
//       sort(nums.begin(),nums.end());
//       long  res = 0;
//       long  M = 1e9 + 7;
//       for (int j = 1; j < n-1; ++j) {
//         int k = n-1;
//         for(int i = 0; i < j; ++i) {
//           int count1 = 1;
//           int count2 = 0;

//           while( i+1 < j && nums[i+1] == nums[i]) {
//             count1++;
//             i++;
//           }
//           while(k > j && nums[i] + nums[j] + nums[k] > target) {
//             k--;
//           }
//           while(k > j && nums[i] + nums[j] + nums[k] == target) {
//             count2++;
//             k--;
//           }
//           res += count1*count2;
//           res %= M;
//         }
//       }
//       return res;
//     }
  int threeSumMulti(vector<int>& arr, int target) {
    int n = arr.size();
    vector<long long> freq(101,0);
    long long M = 1e9 +7;
    long long res = 0;
    for(int num: arr) freq[num]++;
    for(int i =0; i< 101; i++){
      if (freq[i] == 0) continue;
      for(int j = i; j <101; j++) {
        int k = target - i -j;
        if(k >100 || k < j || freq[j] ==0 ||freq[k] == 0) continue;
        else if(i == j && j == k) res += (freq[i]*(freq[j]-1)*(freq[k]-2)/6);
        else if(i == j) res += (freq[i]*(freq[j]-1)*freq[k])/2;
        else if(j == k) res += freq[i]*(freq[j]-1)*freq[k]/2;
        else if(i == k) res += freq[i]*(freq[j])*(freq[k]-1)/2;
        else res += freq[i]*freq[j]*freq[k];
        res %= M;
      }
    }
    return res;
  }
};
