class Solution {
public:
    string getHint(string secret, string guess) 
    {
        int n=secret.length();
        int i;
        int bull=0;
        for(i=0; i<n; i++)
        {
            if(secret[i]==guess[i])
            { 
                bull++;
                secret[i]='p';
                guess[i]='p';
            }    
        }
        int cow=0;
        
        int j;
        for(i=0; i<n; i++)
        {
            if(guess[i]!='p')
            {
               for(j=0; j<n; j++)
                 {
                     if(guess[i]==secret[j])
                     {
                         cow++;
                         guess[i]='p';
                         secret[j]='p';
                         break;
                     }
                 }
            }
            else
            {
                continue;
            }
           
        }
    
        
        string a=to_string(bull);
        string b=to_string(cow);
        return a+"A"+b+"B";
    }
};
