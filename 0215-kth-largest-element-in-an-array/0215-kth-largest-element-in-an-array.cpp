class Solution {
public:
    //priority queue way
    // int findKthLargest(vector<int>& nums, int k) {
    //     priority_queue<int> maxHp(nums.begin(),nums.end());
    //     for(int i=1;i<k;i++) {
    //         maxHp.pop();
    //     } 
    //     return maxHp.top();
    // }
    // arrry heap
    int findKthLargest(vector<int>& nums, int k) {
        for(int i = nums.size()/2-1;i>=0;i--) {
            heapify(nums, i);
        }
        for(int i = 1; i<k; i++) {
            nums[0] = nums.back();
            nums.pop_back();
            heapify(nums, 0);
        }
        return nums[0];
       
    }
    void heapify(vector<int>& nums , int root) {
        int N = nums.size();
        while(true) {
            int biggest = root;
            int l = root*2+1;
            int r = root*2+2;

            if(l<N &&nums[biggest]<nums[l]) biggest = l;
            if(r<N &&nums[biggest]<nums[r]) biggest = r;
            if(biggest == root) break;

            swap(nums[biggest],nums[root]);
            root = biggest;
        }
    }
};