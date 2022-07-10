class Solution {
public:
    int myAtoi(string s) {
        long long num = 0;
        int flag_sign = 0, flag = 0, sign = 1;
        for(auto ch : s) {
            int x = (int)(ch-'0');
            if(ch == '-' && flag_sign == 0) {
                sign = -1;
                flag_sign = 1;
                continue;
            }
            else if(ch == '+' && flag_sign == 0) {
                sign = 1;
                flag_sign = 1;
                continue;
            }
            else if(x >=0 && x<=9) {
                flag_sign = 1;
                flag = 1;
                num = (long long)(num * 10) + (long long)x;
                if(num > INT_MAX && sign==1) return INT_MAX;
                else if(num > INT_MAX && sign==-1) return INT_MIN;
            }
            else if(flag == 1 && ch == ' ') {
                break;
            }
            else if(flag_sign == 1 && ch == ' ') {
                break;
            }
            else if(ch == ' ') continue;
            else break;
        }
        num *= sign;
        return num;
    }
};
