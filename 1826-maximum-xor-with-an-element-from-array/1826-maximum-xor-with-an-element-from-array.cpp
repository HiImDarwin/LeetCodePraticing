class Solution {
    struct TrieNode {
      TrieNode () {
        next[0] = next[1] = nullptr;
      }
      TrieNode* next[2];
    };
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
      TrieNode* root = new TrieNode();
      int numIdx = 0;
      int n = nums.size();
      sort(nums.begin(), nums.end());
      vector<array<int,3>> q2;
      for (int i = 0; i < queries.size(); i++) {
          q2.push_back({queries[i][0], queries[i][1], i});
      }
      sort(q2.begin(), q2.end(), [](auto &a, auto &b){ return a[1] < b[1]; });
      
      vector<int> res(queries.size());
      for (auto& query : q2) {
        int x = query[0];
        int m = query[1];
        int idx = query[2];
        while (numIdx < n && nums[numIdx] <= m) {
          TrieNode* curr = root;
          int num = nums[numIdx];
          for (int i = 31; i >= 0; --i) {
            if (curr->next[(num >> i) & 1] == nullptr) {
              TrieNode* newNode = new TrieNode();
              curr->next[(num >> i) & 1] = newNode;
            }
            curr = curr->next[(num >> i) & 1];
          }
          numIdx++;
        }
        bool notFound = false;
        TrieNode* curr = root;
        int xorNum = 0;
        if (!curr->next[0] && !curr->next[1]) {
          res[idx] = -1;
          continue;
        }
        for (int i = 31; i >= 0; --i) {
          if (curr->next[1-((x >> i) & 1)]) {
            curr = curr->next[1-((x >> i) & 1)];
            xorNum ^= (1 << i);
          } else {
            curr = curr->next[(x >> i) & 1];
          }
        }
        res[idx] = xorNum;
      }
      return res;
    }
};



// class Solution {
//     struct TrieNode {
//       TrieNode () {
//         next[0] = next[1] = nullptr;
//       }
//       TrieNode* next[2];
//     };
// public:
//     vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
//       TrieNode* root = new TrieNode();
//       int numIdx = 0;
//       int n = nums.size();
//       sort(nums.begin(), nums.end());
//       sort(queries.begin(),queries.end(), [](vector<int>& a, vector<int>& b){
//         return a[1] < b[1];
//       });
      

//       vector<int> res;
//       for (auto& query : queries) {
//         int x = query[0];
//         int m = query[1];
//         while (numIdx < n)
//         // for (int& num : nums) {
//         //   TrieNode* curr = root;
//         //   for (int i = 31; i >= 0; --i) {
//         //     if (curr->next[(num >> i) & 1] == nullptr) {
//         //       TrieNode* newNode = new TrieNode();
//         //       curr->next[(num >> i) & 1] = newNode;
//         //     }
//         //     curr = curr->next[(num >> i) & 1];
//         //   }
//         // }



//         bool smallerThanM = false;
//         bool notfound = false;
//         int xorNum = 0;
//         TrieNode* curr = root;

//         for (int i = 31; i >= 0; --i) {
//           int wantDigit = 1 - ((x >> i) & 1);
//           int mDigit = (m >> i) & 1;
//           if (smallerThanM) {
//             if (curr->next[wantDigit]) {
//               curr = curr->next[wantDigit];
//               xorNum ^= (1 << i);
//             } else {
//               curr = curr->next[1-wantDigit];
//             }
//           } else {
//             if (mDigit == 0) {
//               if (curr->next[0] == nullptr) {
//                 notfound = true;
//                 break;
//               }
//               if (wantDigit == 0) {
//                 xorNum ^= (1<<i);
//               }
//               curr = curr->next[0];
//             } else {
//               if (wantDigit == 0 && curr->next[0]) {
//                 smallerThanM = true;
//                 curr = curr->next[0];
//                 xorNum ^= (1<<i);
//               } else if (wantDigit == 1 && !curr->next[1]) {
//                 smallerThanM = true;
//                 curr = curr->next[0];
//               } else {
//                 if (wantDigit == 1) {
//                   xorNum ^= (1<<i);
//                 }
//                 curr = curr->next[1];  
//               }
//             }
//           }
//         }
//         if (notfound) {
//           res.push_back(-1);
//         } else {
//           res.push_back(xorNum);
//         }
//       }
//       return res;
//     }
// };