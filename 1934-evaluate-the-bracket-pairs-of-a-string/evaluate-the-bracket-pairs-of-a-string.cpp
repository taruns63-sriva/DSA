class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto& k : knowledge) {
            mp[k[0]] = k[1];
        }
        string result;
        for (int i = 0; i < s.size(); i++) {

            if (s[i] != '(') {
                result += s[i];
                continue;
            }
            int j = i + 1;
            string key;

            while (s[j] != ')') {
                key += s[j];
                j++;
            }
            if (mp.find(key) != mp.end()) {
                result += mp[key];
            } else {
                result += '?';
            }
            i = j;
        }
        return result;
    }
};