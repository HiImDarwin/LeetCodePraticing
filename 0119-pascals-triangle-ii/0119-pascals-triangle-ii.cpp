class Solution {
public:
    //Dynamic programming
    // vector<int> getRow(int rowIndex) {
    //     vector<vector<int>> res;
    //     for(int i=0; i<=rowIndex ;i++) {
    //         res.push_back(vector<int> (i+1,1));
    //     }
    //     if(rowIndex < 2 ) return res[rowIndex];
    //     for(int row=2; row<=rowIndex; row++) {
    //         for(int col=1; col<row;col++) {
    //             res[row][col] = res[row-1][col-1] + res[row-1][col];
    //         }
    //     }
    //     return res[rowIndex];
    // }
    //Reduce the space complexity
    // only use one vector to do the dp
    // renew the matrix from reverse order, with this don't need other parameter
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1,1);
        for(int row=2; row<=rowIndex; row++) {
            for(int col=row-1; col>0; col--) {
                res[col] = res[col]+res[col-1];
            }
        }
        return res;
    }
};