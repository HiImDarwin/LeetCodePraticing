class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long total = 0;
        int maxVal = 0;
        for (int m : milestones) {
            total += m;
            maxVal = max(maxVal, m);
        }
        if (maxVal <= total - maxVal) return total;
        return 2LL * (total - maxVal) + 1;
    }
};