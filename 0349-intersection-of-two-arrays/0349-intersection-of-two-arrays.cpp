class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> old;
        int m = nums1.size();
        int n = nums2.size();
        if(m==0 || n ==0) return {};
        vector<int> *shorter,*longer;
        if(m<n){
            shorter = &nums1;
            longer = &nums2; 
        } else {
            shorter = &nums2;
            longer = &nums1;
        }
        for(int i=0; i<shorter->size(); i++){
            int val = (*shorter)[i];
            if(old.count(val)) continue;
            for(int j=0; j<longer->size(); j++){
                if((*shorter)[i] == (*longer)[j]){
                    old.insert((*shorter)[i]);
                    res.push_back((*shorter)[i]);
                    break;
                }
            }
        }
        return res;   
    }
};