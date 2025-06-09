class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int upper=0;
        long long int sum=0;
        for(int &x: piles){
            upper = max(upper,x);
            sum += x;
        }
        int lower = (sum+h-1)/h;
        while(upper>=lower) {
            int count = 0;
            int mid = lower+ (upper-lower)/2;
            for(int &x: piles) {
               count += (x+mid-1)/mid;
            }
            if(count <=h) {
                upper = mid-1;
            } else {
                lower = mid+1;
            }
        }
        return lower;
    }
};