class Solution {
public:
    bool isVowel(char c){
       return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    bool halvesAreAlike(string s) {
        int n=s.size()/2;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(isVowel(s[i]))
            cnt++;
        }
        for(int i=n;i<s.size();i++){
            if(isVowel(s[i]))
            cnt--;
        }
        return cnt==0;
    }
};