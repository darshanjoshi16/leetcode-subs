class Solution {
public:
    int romanToInt(string s) {
      
      //it creates the unorder mapping of one to one element of char data type to int data type
         unordered_map<char,int>mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
      //initialize the variable for the summation of every character for the roman to int conversion
        int sum=0;
        int i=0;
      
      //traversing the string from begining to its full length
        while(i<s.length())
        {
          //if the mapped value of i index is less than i+1, then it will consider as sum of i+1 - i
          //example: MCMXCIV
          // Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
            if(mp[s[i]]<mp[s[i+1]])
               {
                sum+=mp[s[i+1]]-mp[s[i]];
                i=i+2;
            }
          //if the i index value is greater than i+1 value mapped then, it will consider the sum of ith index into current sum value
            else
            {
                 sum+=mp[s[i]];i++;
            }
        
        }
        return sum;
        
    }
};
