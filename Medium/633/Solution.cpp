class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c==0 || c==1)return true;
         long long left=0,right=sqrt(c);  // if left==0 right=sqrt(c)
        while(left<=right)
        {
            long int ans =left*left+right*right;  //simple binary search
            if(ans<c)left++;
            else if(ans>c)right--;
            else return true;
        }
        return false;
       
    }
};
