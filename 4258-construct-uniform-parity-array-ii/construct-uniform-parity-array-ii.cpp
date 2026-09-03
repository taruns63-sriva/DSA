class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        long long minOdd = LLONG_MAX;

        for (auto x : nums1) {
            if (x % 2)
                minOdd = min(minOdd, (long long)x);
        }
        if (minOdd == LLONG_MAX)
            return true;
        for (auto x : nums1) {
            if (x % 2 == 0) {
                if (x <= minOdd)
                    return false;
            }
        }
        return true;
    }
};