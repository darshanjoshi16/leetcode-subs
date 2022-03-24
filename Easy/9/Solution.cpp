class Solution {
public:
    bool isPalindrome(int x) {
        
        //if the number is negetive then it can't be the palindrome
        
        if(x<0){
            return false;
        }
        
        else
        {
            //conversion of the integer to string
            string s=to_string(x);
            string r=s;
            //reversing the string so that we can know the palindrome
            reverse(r.begin(),r.end());
            if(s==r)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
       
        
    }
};
