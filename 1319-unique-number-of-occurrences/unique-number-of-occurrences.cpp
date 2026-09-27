class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int num:arr){
            mp[num]++;
        }
        unordered_map<int,int>f;
        for(auto& pair: mp){
            f[pair.second]++;
            if(f[pair.second]>1){
                return false;
            }
        }
        return true;
    }
};