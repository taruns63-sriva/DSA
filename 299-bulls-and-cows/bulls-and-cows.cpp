class Solution {
public:
    string getHint(string s, string g) {
        vector<int>freqs(10,0);
        vector<int>freqg(10,0);
        int n=s.size();
        int bull=0;
        for(int i=0;i<n;i++){
            if(s[i]==g[i]){
                bull++;
                s[i]='#';
                g[i]='#';
            }
            else{
                freqs[s[i]-'0']++;
                freqg[g[i]-'0']++;
            }
        }
        int cows=0;
        for(int i=0;i<10;i++){
            cows+=min(freqs[i],freqg[i]);
        }
        return to_string(bull)+'A'+to_string(cows)+'B';
        
    }
};