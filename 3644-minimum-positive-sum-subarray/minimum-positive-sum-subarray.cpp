class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int sol=INT_MAX,sum=0;
        int i=0,j=l-1;
        for(int i=0;i<=nums.size()-l;i++){
            sum=0;
            for(int b=i;b<i+l-1;b++)
            sum+=nums[b];
            for(int k=i+l-1;k<i+r && k<nums.size();k++){
                sum+=nums[k];
                if(sum>0)
                sol=min(sol,sum);
            }
        }
        if(sol==INT_MAX)
        return -1;
        return sol;
    }
};