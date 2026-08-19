class Solution {
public:
    int solve(vector<int>& nums,int a, int b) {
        int p1=0;
        int p2=0;
        for(int i=a;i<=b;i++){
            int curr=max(p1,p2 +nums[i]);
            p2=p1;
            p1=curr;
        }
        return p1;
    }
    int rob(vector<int>& nums) {
     int n=nums.size();
     if(n==1){
        return nums[0];
     }
     int c1=solve(nums,0,n-2);
     int c2=solve(nums,1,n-1);
        return max(c1,c2);
      }
};