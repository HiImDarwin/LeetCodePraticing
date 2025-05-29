class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator root=nums.begin();
        vector<int>::iterator peek;
        int remove=0;
        while(root!=nums.end()) {
            peek=root+1;
            while(peek!=nums.end() && *root == *peek) {
                remove++;
                nums.erase(peek);
                peek=root+1;
            }
            root++;
        }
        return nums.size();
    }
};