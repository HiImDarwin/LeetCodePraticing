class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0) return {0};
        vector<int> res(n+1);
        res[0] = 0;
        int index = 1;
        int powOfTwo = 1;
        while (powOfTwo <= n) {
            index = 1;
            res[powOfTwo] = 1;
            while( index < powOfTwo && index+powOfTwo <=n) {
                res[powOfTwo+index] = res[index]+1;
                index++;
            }
            powOfTwo *= 2;
        } 
        return res;
    }
};