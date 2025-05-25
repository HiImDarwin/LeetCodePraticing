class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(len <= 1) return s;
        int max_len = 1;
        
        std::string maxStr = s.substr(0,1);
        s = std::regex_replace(s,std::regex(""), "#");
        std::vector<int> dp(s.length(),0);
        int center = 0;
        int right = 0;
        for (int i = 0; i<s.length(); i++) {
            if (i<right) {
                dp[i] = std::min(right-i, dp[2*center-i]);
            }

            while (i-dp[i]-1 >=0 && i+dp[i] +1<s.length() && s[i-dp[i]-1] == s[i+dp[i]+1]) {
                dp[i]++;
            }

            if(i +dp[i] >right) {
                center = i;
                right = i+dp[i];
            }

            if (dp[i] > max_len) {
                max_len = dp[i];
                maxStr =s.substr(i-dp[i], 2*dp[i]+1);
                maxStr.erase(std::remove(maxStr.begin(), maxStr.end(), '#'), maxStr.end());
            }
        }
        return maxStr;
    }
};