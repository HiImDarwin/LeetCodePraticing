class Solution {
public:
    // vector<int> searchRange(vector<int>& nums, int target) {
    //     int start=0,end=nums.size()-1,mid;
    //     while (start<=end) {
    //         mid = start+(end-start)/2;
    //         if(nums[mid] == target) {
    //             break;
    //         } else if(nums[mid] > target) {
    //             end = mid-1;
    //         } else {
    //             start = mid+1;
    //         }
    //     }
    //     if(start > end) return {-1,-1} ;
    //     start = mid;
    //     end = mid;
    //     while(start >=0 && nums[mid] == nums[start] ){start--;}
    //     while(end<nums.size() && nums[mid] == nums[end]){end++;}
    //     return {start+1,end-1};
    // }

    // two BinarySearch
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findfirst(nums,target);
        int last = findlast(nums,target);
        return {first,last};
    }

    int findfirst(vector<int>& nums, int target) {
        int first = 0;
        int last = nums.size()-1;
        int mid;
        int res = -1;
        while(first<=last) {
            mid = first +(last-first)/2;
            if(nums[mid] < target) {
                first = mid+1;
            } else {
                if(nums[mid] == target) {
                    res = mid;
                }
                last = mid-1;
            }
        }
        return res;
    }

    int findlast(vector<int>& nums, int target) {
        int first = 0;
        int last = nums.size()-1;
        int mid;
        int res = -1;
        while(first<=last) {
            mid = first +(last-first)/2;
            if(nums[mid] > target) {
                last = mid-1;
            } else {
                if(nums[mid] == target) {
                    res = mid;
                }
                first = mid+1;
            }
        }
        return res;
    }
};