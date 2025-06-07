class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> tmp; //odd number evenprefix
        tmp[0] = 0;
        int res =0;
        int oddCount=0;
        int evenCount=0;
        int preOddRes=0;
        for(int &x:nums){
            if(x%2==0){
                evenCount++;
                res += preOddRes;
            } else {
                oddCount++;
                tmp[oddCount] = evenCount;
                evenCount =0;
                if(tmp.count(oddCount-k)) {
                    preOddRes =tmp[oddCount-k+1]+1;
                    res += preOddRes;
                    
                }
            }
        }
        return res;
    }
};