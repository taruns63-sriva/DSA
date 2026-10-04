class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int c=0;
        set<pair<int,int>> ans;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(i!=j)
                {
                    if(abs(nums[i]-nums[j]) == k)
                       {
                         ans.insert({min(nums[i], nums[j]), max(nums[i], nums[j])});
                       }
                }
            }
        }
        return ans.size();
        
    }
};