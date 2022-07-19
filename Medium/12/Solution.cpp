class Solution {
public:
    
    //  Dry run some exmaples 
    /*
        3999 = 3000 + 900 + 90 + 9 = MMM + CM + XC + IX
        // Go backward only one positions
        2835 = 2000 + 800 + 30 + 5 = MM + DCC + XXX + V  (WRONG WAY : MM + CCM + XXX + V)
        4000 = MMMM

    */
    
    // DRY RUN of num = 249 for the below code
    // 249 = 200 + 40 + 9 = 
    /* 
        Ist Pass :
        --------
        last digit = 9 , place value = x = 1
        1. multiply by place value = 9*1 = 9 
        2  9 is not found in map
        3. Its nearest by place value x=1, 9+1 = 10, 10 is present in map
        4. write mp[1]+mp[10] = "IX" for '9'
        5. ans = "IX"
        
        IInd Pass :
        ---------
        last digit = 4 , place value = x = 10
        1. multiply by place value = 4*10 = 40
        2  40 is not found in map
        3. Its nearest by place value x=10, 40+10 = 50, 50 is present in map
        4. write mp[10]+mp[50] = "XL" for '40'
        5. ans = "XLIX"
        
        IIIrd Pass :
        ---------
        last digit = 2 , place value = x = 100
        1. multiply by place value = 2*100 = 200
        2  200 is not found in map
        3. Its nearest by place value x=100, 200+100 = 300, 300 is not present in map
        4. So perform subtraction by place value x=100, 200-100 = 100, 100 is present in map
        5. write mp[100]+mp[100] = "CC" for '200'
        6. ans = "CCXLIX"
        
        DONE !
    */
    string intToRoman(int num) 
    {
        unordered_map<int,string>mp = {{1,"I"},{5,"V"},{10,"X"},{50,"L"},{100,"C"},{500,"D"},{1000,"M"}};
        
        int x=1;
        string ans="";
        while(num>0)
        {
            int d=num%10;                           // Last digit of a number
            d*=x;                                   // Multiply by its place value (like 1, 10, 100, 1000)
            while(d>0)
            {
                if(mp.find(d)!=mp.end()){           // find the digit in the map - direct 
                    ans = mp[d] + ans;
                    d = 0;
                } 
                else if(mp.find(d+x)!=mp.end())      // or find the approx nearest in the map. // like 40 nearest to 50
                {
                    ans = mp[x] + mp[d+x] + ans;
                    d = 0;
                }
                else                            // iterate the place value mapped value until it matches the map value
                {
                    ans = mp[x] + ans;
                    d -= x;
                } 
            }
            num/=10; // remove the last digit from the number
            x*=10; // increment the place value.
        }
        return ans;
    }
};
