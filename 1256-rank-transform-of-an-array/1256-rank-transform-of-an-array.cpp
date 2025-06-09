class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,vector<int>> bucket;
        for(int i=0; i<arr.size();i++) {
            if(bucket.count(arr[i])) {
                bucket[arr[i]].push_back(i);
            } else {
                bucket[arr[i]] = vector<int>(1,i); 
            }
        }
        auto bucketIt = bucket.begin();
        int i=1;
        while(bucketIt!= bucket.end()) {
            for(int &idx : (*bucketIt).second ) {
                arr[idx] = i;
            }
            bucketIt++;
            i++;
        }
        return arr;
    }
};