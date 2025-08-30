class Solution {
public:
    string largestNumber(vector<int>& nums) {
      vector<string> numStr;
      for (int i = 0; i < nums.size(); ++i) {
        numStr.push_back(to_string(nums[i]));
      }

      sort(numStr.begin(), numStr.end(), [](const string& a, const string& b){
        return (a + b) > (b + a);
      });

      string res;
      for (auto& s : numStr) {
        res += s;
      }
       
      return res[0] == '0' ? "0" : res;
    }
};

/*

[3,30,34,5,9]

*/