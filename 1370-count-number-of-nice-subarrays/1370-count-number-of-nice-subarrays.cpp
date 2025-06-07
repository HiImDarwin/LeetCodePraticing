class Solution {
public:
    // int numberOfSubarrays(vector<int>& nums, int k) {
    //     unordered_map<int,int> tmp; //odd number evenprefix
    //     tmp[0] = 0;
    //     int res =0;
    //     int oddCount=0;
    //     int evenCount=0;
    //     int preOddRes=0;
    //     for(int &x:nums){
    //         if(x%2==0){
    //             evenCount++;
    //             res += preOddRes;
    //         } else {
    //             oddCount++;
    //             tmp[oddCount] = evenCount;
    //             evenCount =0;
    //             if(tmp.count(oddCount-k)) {
    //                 preOddRes =tmp[oddCount-k+1]+1;
    //                 res += preOddRes;
                    
    //             }
    //         }
    //     }
    //     return res;
    // }

    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        freq[0] = 1;
        int odd=0, res =0;
        for(int x:nums) {
            if(x%2==1) odd++;
            if(freq.count(odd-k)){
                res+= freq[odd-k];
            }
            freq[odd]++; //這行是精隨，他把odd之後出現過的even數量都加進去了，而且因為odd本身res已經寫進去，往後加不影響
        }
        return res;    
    }
};