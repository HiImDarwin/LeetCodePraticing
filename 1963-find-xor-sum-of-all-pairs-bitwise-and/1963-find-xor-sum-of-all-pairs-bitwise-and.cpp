class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
      int arr1XOR = 0, arr2XOR = 0;;
      for (auto& num : arr1) {
        arr1XOR ^= num;
      }
      for (auto& num : arr2) {
        arr2XOR ^= num;
      }
      return arr1XOR & arr2XOR;
    }
};

/*

(1 & 6) ^ (2 & 6) ^ (3 & 6)
1&2&3 = 0 ^ 6 = 6
1|2|3 = 3 ^ 6 = 
0 ^ 2 ^ 2 = 0

(a1^a2) & (b1^b2) =  (a1&b1) ^ (a1&b2) ^ (a2&b1) ^ (a2&b2)
*/