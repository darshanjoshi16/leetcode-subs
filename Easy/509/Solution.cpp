class Solution {
public:
    int fib(int n) 
    {
        // Base Case
        if (n == 0 || n==1)    
            return n;
  
        return fib(n-1)+fib(n-2);
    }
};
