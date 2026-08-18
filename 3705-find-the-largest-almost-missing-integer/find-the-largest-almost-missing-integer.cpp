class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==1){
            unordered_map<int,int>counts;
           for(int num:nums)
           counts[num]++;

         int ans=-1;
         for(auto & [num,count] :counts)
         if(count==1){
            ans=max(ans,num);
         }
         return ans;
        }
        if(k==n){
            return *max_element(nums.begin(),nums.end());
        }
          unordered_map<int,int>counts;
           for(int num:nums)
           counts[num]++;

         int ans=-1;
        
         if(counts[nums[0]]==1){
            ans=max(ans,nums[0]);
         }
          if(counts[nums[n-1]]==1){
            ans=max(ans,nums[n-1]);
         }
         return ans;
    }
};