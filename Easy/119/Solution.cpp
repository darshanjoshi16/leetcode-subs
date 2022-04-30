class Solution {
public:
    int combination(int n,int r){
        long long int x=r,y=1,i=1;
        
        while(x--){
            y *= n;
            n--;
            if(i<=r && y%i==0){
                y = y/i;
                i++;
            }
        }
        return y ;
    }
    vector<int> getRow(int n) {
        vector<int> v;
        for(int i=0;i<n+1;i++){
            v.push_back(combination(n,i));
        }
        return v;
    }
};
