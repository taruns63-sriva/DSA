class Solution {
private:
    string f(string t){
        int sum=0;
        for(auto& i:t){
            sum+=(i-'0');
        }
        return to_string(sum);
    }
public:
    string digitSum(string s, int k) {
        int n=s.size();
        if(k>n) return s;

        while(s.size()>k){
            string x;
            for(int i=0;i<s.size();i+=k){
                x+=f(s.substr(i,k));
            }
            s=x;
        }
        return s;
    }
};