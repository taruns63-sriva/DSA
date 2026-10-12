class Solution {
public:
    bool checkbit(int n,int i){
        return (((n>>i)&1)==1);
    }
    int maxSum(vector<int>& nums, int k) {
        int mod=1e9+7;

        int n=nums.size();
        vector<int> v;
        for(int i=0;i<31;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(checkbit(nums[j],i)){
                    cnt++;
                }
            }
            v.push_back(cnt);
        }
        long long square=0;
        for(int i=0;i<k;i++){
            long long m=0;
            for(int j=0;j<31;j++){
                if(v[j]>i){
                    m=(m|(1LL<<j));
                }
            }
            if(m==0) break;
            square=(square+(1LL*m*m))%mod;
        }
        return square;
    }
};