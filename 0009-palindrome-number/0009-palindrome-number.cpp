class Solution {
public:
    bool isPalindrome(int x) {
        string tmp = to_string(x);
        int left =0,right = tmp.length()-1;
        while(left<=right){
            if(tmp[left++] != tmp[right--]) return false;
        }
        return true;
    }
};