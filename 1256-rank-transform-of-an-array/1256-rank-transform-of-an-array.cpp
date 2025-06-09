class Solution {
public:
    // vector<int> arrayRankTransform(vector<int>& arr) {
    //     map<int,vector<int>> bucket;
    //     for(int i=0; i<arr.size();i++) {
    //         if(bucket.count(arr[i])) {
    //             bucket[arr[i]].push_back(i);
    //         } else {
    //             bucket[arr[i]] = vector<int>(1,i); 
    //         }
    //     }
    //     auto bucketIt = bucket.begin();
    //     int i=1;
    //     while(bucketIt!= bucket.end()) {
    //         for(int &idx : (*bucketIt).second ) {
    //             arr[idx] = i;
    //         }
    //         bucketIt++;
    //         i++;
    //     }
    //     return arr;
    // }
    
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> rank = arr;
        sort(rank.begin(),rank.end());
        unordered_map<int,int> tmp;
        int rankIdx=1;
        for(int&x : rank) {
            if(tmp.count(x) ==0) {
                tmp[x] = rankIdx++;
            }
        }

        for(int i =0;i<arr.size();i++) {
            arr[i] = tmp[arr[i]];
        }

        return arr;
    }
};