class Solution {
public:
    int dayOfYear(string date) {
       
        int year = stoi(date.substr(0, 4)), month = stoi(date.substr(5, 2)), day = stoi(date.substr(8));
        int c1=0;
          if((year %4 ==0 && year % 100!=0) || (year % 400 ==0))
           c1++;
          vector<int >v={0,31,59,90,120,151,181,212,243,273,304,334};
         
          if(month<3) return v[month-1]+day; 
          else return v[month-1]+day+c1;
    }
};  