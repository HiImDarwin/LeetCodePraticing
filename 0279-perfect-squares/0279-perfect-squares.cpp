class Solution {
public:
    int numSquares(int n) {
        int x = (int) sqrt(n);
        vector<int> squ_num;
        for(int i=1;i*i<=n;i++){
            squ_num.push_back(i*i);
        }

        vector<int> res(n+1,INT_MAX);
        res[0] = 0;
        for(int i=1;i<n+1;i++) {
            for(int num: squ_num) {
                int index = i-num;
                if(index<0) break;
                if(res[index]+1 < res[i]) res[i]=res[index]+1;
            }
        }
        return res[n];
    }
    
};