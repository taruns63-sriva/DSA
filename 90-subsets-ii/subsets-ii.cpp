class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<vector<int> , int>mp ;
        vector<vector<int>>ans ;
        sort(nums.begin(),nums.end());
        ans.push_back(vector<int>());
        for(int i=0 ;i<nums.size() ; i++){
            int n=ans.size();
            for(int j=0 ; j<n ;j++){
                vector<int>temp=ans[j];
                temp.push_back(nums[i]) ;
                if(mp[temp]>0) continue ;
                ans.push_back(temp);
                mp[temp]++;
            }
        }
        return ans; 
    }
};