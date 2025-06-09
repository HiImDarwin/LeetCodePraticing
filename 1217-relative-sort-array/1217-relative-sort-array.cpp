class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> tmp;
        for(int &x : arr1) {
            tmp[x]++;
        }
        int idx1 =0;
        for(int &num: arr2) {
            while(tmp[num]>0){
                arr1[idx1] = num;
                idx1++;
                tmp[num]--;
            }
            tmp.erase(num);
        }

        vector<int> ve;
        for(auto &x: tmp) {
            while(x.second>0){
                ve.push_back(x.first);
                x.second--;
            }
        }
        sort(ve.begin(),ve.end());
        for(int &x: ve) {
            arr1[idx1] =x;
            idx1++;
        }


        return arr1;
    }
};