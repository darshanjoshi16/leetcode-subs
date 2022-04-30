class Solution {
public:
    int nthUglyNumber(int n) {
        int count = 1;
        int two = 0, three = 0, five = 0;

        vector<int> uglyNums; uglyNums.push_back(1);
        while(count < n) {
            int i2 = 2 * uglyNums[two];
            int i3 = 3 * uglyNums[three];
            int i5 = 5 * uglyNums[five];

            int min_ = min(i2, min(i3, i5));
            uglyNums.push_back(min_);
            count++;

            if (min_ == i2) two++;
            if (min_ == i3) three++;
            if (min_ == i5) five++;
        }
        return uglyNums[n - 1];
    }
};
