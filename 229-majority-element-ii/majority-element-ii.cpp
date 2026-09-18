class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> m;
        vector<int> res;
        int n=floor(nums.size()/3);
        for(int j=0;j<nums.size();j++)
        {
            if(m.count(nums[j]) != 0)
            {
                m[nums[j]]++;
            }
            else
            {
                m[nums[j]]=1;
            }
        }map<int,int>::iterator itr=m.begin();
        while(itr != m.end())
        {
            if(itr->second>n)
            {
                res.push_back(itr->first);
            }
            itr++;
        }
        return res;
    }
};