class Solution {
public:
    int subtractProductAndSum(int n) {
        
        //initiliaze the sum and multiplication variables
        int sum = 0, multi=1;
        
        //running the loop till the number is >0
        //here suppose we take example of 234
        while(n>0)
        {
            
            int digits = n % 10; //digits = 234 % 10 = 4
            sum = sum + digits;//sum = 4
            multi = multi * digits;//multi = 4
            n = n / 10;//n becomes 23 and this process is repeating
        }
        //it will return the demanding result
        return multi-sum;
        
    }
};
