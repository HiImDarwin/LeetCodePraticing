class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int right=0;
        int left =1;
        for(int &x: nums){
            right = max(right,x);
        }
        while(left<=right) {
            int mid = left + (right-left)/2;
            int count = 0;
            for(int &x :nums) {
                count += (x+mid-1)/mid;
            }
            if(count <= threshold) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
};