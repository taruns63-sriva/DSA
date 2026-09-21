class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>f;
        f[0] = 1;
        
        int p = 0;
        int ans = 0;
        for(int num : nums) {
            p += num;
            
            int r=p%k;
            if(r<0)
             r += k;
            ans += f[r];
            f[r]++;
        }
        return ans;
    }
};