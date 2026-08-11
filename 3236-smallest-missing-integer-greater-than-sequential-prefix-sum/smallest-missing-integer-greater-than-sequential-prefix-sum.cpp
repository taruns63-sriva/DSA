class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>num_set(nums.begin(),nums.end());

        int ans=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1)
                ans += nums[i];
        
            else
               break;
        }
        while(num_set.count(ans)){
            ans +=1;
        }
        return ans;
    }
};