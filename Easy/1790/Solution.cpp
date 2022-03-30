class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int>indx; //storing the index
        for(int i=0;i<s1.size();i++){
                //if the values are not equal then store its index.
            if(s1[i]!=s2[i]){ 
                indx.push_back(i);
            }
            // if we have found more than 2 index where value does not match, 
            // then break.
            if (indx.size()>=2) break; 
        }
        // if size==1, then we cannot swap, as swapping needs 2 values.
        if(indx.size()==1)return false;
        // if size of idx is zero then strings are already equal
        else if(indx.size()==0) return true; 
        else {
            swap(s2[indx[0]],s2[indx[1]]); //swaping the indexes that we have found.
            return s1==s2; //if after swap both the string are same.
        }
    }
};
