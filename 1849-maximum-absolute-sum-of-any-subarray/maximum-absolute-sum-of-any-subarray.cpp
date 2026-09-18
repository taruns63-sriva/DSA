class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int maxEnding = nums[0];
        int minEnding = nums[0];
        int res=abs(nums[0]);
        for(int i=1;i<n;i++){
            maxEnding = max(maxEnding+nums[i],nums[i]);
            minEnding = min(minEnding+nums[i],nums[i]);
            res = max(res,max(abs(minEnding),abs(maxEnding)));
        }
        return res;
    }
};