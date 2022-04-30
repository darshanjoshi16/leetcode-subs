class Solution {
public:
    int numTrees(int n) {
        int k = 2*n;
        int r = n;
        long cal =1;
        if(k>r){
            r = k-r;
        }
        for(int i = 0;i<r;i++){
            cal = cal*(k-i);
            cal = cal/(i+1);
        }
        cal = cal/(n+1);
        return cal;
    }
};
