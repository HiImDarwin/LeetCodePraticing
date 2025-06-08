class Solution {
public:
    bool validPalindrome(string s) {
       return isPalindrome(s,0,s.length()-1,false);
    }
    bool isPalindrome (const string & s, int left, int right, bool deleted) {
        while(left<right) {
            if(s[left] == s[right]) {
                left++;
                right--;
            } else {
                if(deleted) return false;
                return isPalindrome(s, left+1, right, true) || isPalindrome(s, left, right-1, true);
            }
        }
        return true;
    }
};