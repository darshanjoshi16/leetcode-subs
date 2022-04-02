class Solution {
public:
    
     bool isValid(vector<vector<int>>& image,int i,int j, int n,int m,int color){
            if(i>=0 && i<n && j>=0 && j<m && image[i][j]==color)
                return true;
            return false;
        }
    
    void floodilledRec(vector<vector<int>>& image,int i,int j,int n,int m,int color,int newcolor){
        
        image[i][j]=newcolor;
        
        if(isValid(image,i+1,j,n,m,color))
           floodilledRec(image,i+1,j,n,m,color,newcolor); 
        
        if(isValid(image,i-1,j,n,m,color))
           floodilledRec(image,i-1,j,n,m,color,newcolor); 
        
        if(isValid(image,i,j+1,n,m,color))
           floodilledRec(image,i,j+1,n,m,color,newcolor); 
        
        if(isValid(image,i,j-1,n,m,color))
           floodilledRec(image,i,j-1,n,m,color,newcolor); 
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
       int n=image.size();
        int m=image[0].size();
        int color=image[sr][sc];
        if(color==newColor)
            return image;
        floodilledRec(image,sr,sc,n,m,color,newColor);
        return image;
        
    }
};
