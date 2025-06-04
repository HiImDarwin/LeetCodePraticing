class Solution {
public:
    // vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    //     vector<int> res;
    //     unordered_set<int> old;
    //     int m = nums1.size();
    //     int n = nums2.size();
    //     if(m==0 || n ==0) return {};
    //     vector<int> *shorter,*longer;
    //     if(m<n){
    //         shorter = &nums1;
    //         longer = &nums2; 
    //     } else {
    //         shorter = &nums2;
    //         longer = &nums1;
    //     }
    //     for(int i=0; i<shorter->size(); i++){
    //         int val = (*shorter)[i];
    //         if(old.count(val)) continue;
    //         for(int j=0; j<longer->size(); j++){
    //             if((*shorter)[i] == (*longer)[j]){
    //                 old.insert((*shorter)[i]);
    //                 res.push_back((*shorter)[i]);
    //                 break;
    //             }
    //         }
    //     }
    //     return res;   
    // }

    // time complexity O(MlogM+NlogN)

    // vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    //     vector<int> res;
    //     sort(nums1.begin(),nums1.end());
    //     sort(nums2.begin(),nums2.end());
    //     int i=0;
    //     int j=0;
    //     while( i<nums1.size() && j<nums2.size() ) {
    //         if(nums1[i] == nums2[j]){
    //             res.push_back(nums1[i]);
    //             while(++i<nums1.size() && nums1[i] == nums1[i-1]) {}
    //             while(++j<nums2.size() && nums2[j]==nums2[j-1]){}
    //         } else if(nums1[i]>nums2[j]){
    //             while(++j<nums2.size() && nums2[j]==nums2[j-1]){}
    //         } else {
    //             while(++i<nums1.size() && nums1[i]==nums1[i-1]){}
    //         }
    //     }
    //     return res;
    // }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> tmp1(nums1.begin(),nums1.end());
        unordered_set<int> res;
        for(int &x : nums2){
            if(tmp1.count(x)) {
                res.insert(x);
            }
        }
        return vector<int> (res.begin(),res.end());
    }   
};