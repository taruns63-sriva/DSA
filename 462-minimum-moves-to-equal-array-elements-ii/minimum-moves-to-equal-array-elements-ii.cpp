class Solution {
public:
    int minMoves2(vector<int>& nums) {
        auto middle = nums.begin() + nums.size() / 2;
        nth_element(nums.begin(), middle, nums.end());
        int median = *middle;
        int moves = 0;
        for (int x : nums) {
            moves += abs(x - median);
        }
        return moves;
    }
};