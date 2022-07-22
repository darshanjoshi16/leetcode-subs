class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
	//create a min interger to track the min length
        int miN=INT_MAX;
		
	//store the first element to compare with others
        string a = strs[0];
		
	//for loop to compare
        for(int i=1; i<strs.size(); i++)
        {
            string temp = strs[i];
            int j=0, k=0, count = 0;
			
		//Increase the count untill characters are same
            while(j<a.length() && k<temp.length() && a[j]==temp[k])
            {
                count++;j++;k++;
            }
			//if count is less than miN then assign count to miN
            miN = min(miN, count);
            
        }
		//return the substr from 0th index to miNth index 
        return a.substr(0, miN);
    }
};
