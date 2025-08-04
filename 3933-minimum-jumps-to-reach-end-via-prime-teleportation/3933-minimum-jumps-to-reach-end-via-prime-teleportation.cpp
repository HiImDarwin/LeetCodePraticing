
class Solution {
public:
    int minJumps(vector<int>& nums) 
    {
      int n = nums.size();
      int maxi = *max_element(nums.begin(), nums.end());
      vector<int> steps(n,INT_MAX);
      unordered_map<int,vector<int>> valToIndex;
      for (int i = 0; i < n; ++i) {
        valToIndex[nums[i]].push_back(i);
      }
      // for(int i = 0; i < n; ++i) {
      //   if (isPrime(nums[i]) && primeIndex.find(nums[i]) == primeIndex.end()) {
      //     primeIndex[nums[i]] = {};
      //   }
      // }
      // for (int i = 0; i < n; i++) {
      //   for (auto& [primeVal, vec] : primeIndex) {
      //     if (nums[i] % primeVal == 0) {
      //       vec.push_back(i);
      //     }
      //   }
      // }

      queue<pair<int,int>> qu;
      qu.push({0,0});
      steps[0] = 0;
      unordered_set <int> used;

      while (!qu.empty()) {
        auto [idx, step] = qu.front();
        qu.pop();
        if (idx + 1 < n && steps[idx + 1] == INT_MAX) {
          steps[idx + 1] = step + 1;
          qu.push({idx + 1, step + 1});
        }
        
        if (idx - 1 >= 0 && steps[idx - 1] == INT_MAX) {
          steps[idx - 1] = step + 1;
          qu.push({idx - 1, step + 1});
        }

        if (isPrime(nums[idx]) == false || used.contains(nums[idx])) continue;

        for (int tar = nums[idx]; tar <= maxi; tar += nums[idx]) {
          if (valToIndex.contains(tar) == false) continue;
          for (auto it : valToIndex[tar]) {
            if (steps[it] != INT_MAX) continue;
            qu.push({it,step+1});
            steps[it] = step+1;
          }
        }
        used.insert(nums[idx]);

        // if (primeIndex.find(nums[idx]) != primeIndex.end()) {
        //   for(auto& jump : primeIndex[nums[idx]]) {
        //     if(steps[jump] != INT_MAX || jump == idx) continue;
        //     steps[jump] = step + 1;
        //     qu.push({jump,step + 1});
        //   }
        //   primeIndex.erase(nums[idx]);
        // }
      }
      return steps[n - 1];
    }

    bool isPrime(int n) 
    {
      static const int MAX_N = 1e6 + 1;
      static vector<bool> sieve = [] {
        vector<bool> is_prime(MAX_N, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i < MAX_N; ++i) {
          if (is_prime[i]) {
            for (int j = i * i; j < MAX_N; j += i) {
              is_prime[j] = false;
            }
          }
        }
        return is_prime;
      }();
      if (n < 0 || n >= MAX_N) return false;
      return sieve[n];
    }
  
};
