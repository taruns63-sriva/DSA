class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map <int,int> cnt;
        if (deck.empty())
            return false;
        for(int i=0; i<deck.size(); i++)
            cnt[deck[i]]++;
        int x = cnt.begin()->second;
        for(auto it: cnt)
        {
            x = gcd(x, it.second);
            if(x==1)
                return false;
        }
        return true;
    }
};