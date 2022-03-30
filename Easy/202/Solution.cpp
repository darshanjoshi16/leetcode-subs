class Solution 
{
    //declaring the public method
public:
    bool isHappy(int n) 
    {
        //temporary assigning the number to another variable
        int temp = n;
        
        //calling another method for main function return
        do 
        {
            temp = isHappyUtil(temp);
            n = isHappyUtil(isHappyUtil(n));
        } while (temp != n);
        
        return n == 1;
    }
    
    //declaring the private method
private:
    //creating the logic for the Happy Number until it satisfy the criteria
    int isHappyUtil(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
};
