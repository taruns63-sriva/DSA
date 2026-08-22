class Solution {
public:
       bool check(string s){
        int hyp=0;
        int punc=0;
        for(int i=0;i<s.size();i++){
            if (isdigit(s[i])){
                return false;
            }
            if(s[i]=='-'){
                hyp++;
                if(i==0 || i==s.size()-1 || hyp>1)
                return false;
                if(!islower(s[i-1]) || !islower(s[i+1]))
                return false;
            } 
            if(s[i]=='!' || s[i]=='.' || s[i]==','){
                punc++;
                if(i !=s.size()-1 || punc>1)
                return false;
            }
         }
         return true;
       }
    int countValidWords(string sentence) {
        int cnt=0;
        sentence.push_back(' ');
        string word ="";
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]==' ' && word !=""){
                if(check(word)){
                    cnt++;
                    cout<<word<<endl;
                }
                word="";
            } else{
                if(sentence[i] !=' ')
                word += sentence[i];
            }
        }
        return cnt;
    }
};