class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        //size of matrix
         int n=mat.size();
        
        //ovelap only possible if length is odd
        int i=0,j=0;
        int ans=0;
        
        //odd length matrix diagonal calculation
        if(n%2!=0){
            for(int a=0;a<n;a++){
                ans+=mat[a][a];
            }
            for(int a=0;a<n;a++){
                ans+=mat[n-1-a][a];
            }
            ans-=mat[n/2][n/2];
            return ans;
        }  
        
        // even length matrix diagonal calculation
        else{
             for(int a=0;a<n;a++){
                ans+=mat[a][a];
            }
            for(int a=0;a<n;a++){
                ans+=mat[n-1-a][a];
            }
            return ans;
        }
        return 0;
        }    
        
};
