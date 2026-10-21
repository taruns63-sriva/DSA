class Solution {
public:
    int minOperations(string s) {
        int size = s.length();
        string temp = s;
        sort(temp.begin(),temp.end());
        if(temp == s) 
          return 0;
        if(size == 2 && temp[0]!=s[0])
          return -1;
        if(temp[0] == s[0] || s[size-1] == temp[size-1]) 
          return 1;
        reverse(temp.begin(),temp.end());
        if( s[0]==temp[0] && s[size-1] == temp[size-1] && temp[0] != temp[1] && temp[size-1] != temp[size-2]) 
         return 3;
        
        return 2;
    }
}; 