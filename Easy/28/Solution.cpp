class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0){
            return 0;
        }
       if(needle.size()>haystack.size()){
           return -1;
       }
        int count= haystack.find(needle);
            return count;
    }
};
