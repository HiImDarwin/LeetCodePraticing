class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size()-1;
        int left = *max_element(weights.begin(),weights.end());
        int right = accumulate(weights.begin(),weights.end(),0);
        while(left<right) { 
            //finding lower bound 
            int mid = left+(right-left)/2;
            if(load(weights,mid) > days) {
                left =mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    int load (vector<int>& weights, int wieght) {
        int count=0;
        int i=0;
        int sum=0;
        while(i<weights.size()) {
            while(i<weights.size() && sum+weights[i]<=wieght) {
                sum += weights[i++];
            }
            sum=0;
            count++;
        }
        return count;
    }
};