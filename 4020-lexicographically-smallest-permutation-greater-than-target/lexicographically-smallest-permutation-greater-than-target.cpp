class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26,0);
        for(char ch : s) {
            cnt[ch-'a']++;
        }      

        string res; 
        for(int i = 0; i<target.size(); i++) {
            int idx = target[i]-'a';
            if(cnt[idx] > 0) {
                cnt[idx]--;

                string a;
                for(int k = 25; k>=0; k--) {
                    a.append(cnt[k],'a'+k);
                }
                string suff = target.substr(i+1);
                if(a > suff) {
                    res.push_back(target[i]);
                    continue;
                }
                cnt[idx]++;
            }
            for(int j = idx+1; j<26; j++) {
                if(cnt[j] > 0) {
                    cnt[j]--;
                    res.push_back('a'+j);
                    for(int k = 0; k<26; k++) {
                        res.append(cnt[k],'a'+k);
                    }
                    return res;
                }
            }
            return "";
        }
        return "";
    }
};