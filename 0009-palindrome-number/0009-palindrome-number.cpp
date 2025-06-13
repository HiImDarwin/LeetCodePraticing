class Solution {
public:
    // bool isPalindrome(int x) {
    //     string tmp = to_string(x);
    //     int left =0,right = tmp.length()-1;
    //     while(left<=right){
    //         if(tmp[left++] != tmp[right--]) return false;
    //     }
    //     return true;
    // }
    bool isPalindrome(int x) {
        if (x<0 || (x%10==0 && x!=0)) return false;
        if (x<10) return true;
        int y =0;
        while (y<x) {
            y =y*10+x%10;
            x/=10;
        }
        return (y == x) || (y/10 ==x);
    
    }
};