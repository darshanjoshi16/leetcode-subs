class Solution {
public:
    string mergeAlternately(string word1, string word2) 
    {
        //defining the size of both input strings
        int size1 = word1.size(), size2 = word2.size();
        
        //initializing the empty string as resultant string
        string ans="";
        
        
        int i=0;
        
        //appending every character into string. which will return merged string till both the string have same length
       
        while(size1 > 0 && size2 > 0)
        {
            ans += word1[i];
            ans += word2[i];
            i++;
            size1--;
            size2--;
        }
        
        //it is the case when one of the string is completely merged but other string has characters left for merging
        while(size1>0)
        {
            ans += word1[i];
            i++;
            size1--;
        }
        while(size2 > 0)
        {
            ans += word2[i];
            i++;
            size2--;
        }
        
        return ans;
        
    }
};
