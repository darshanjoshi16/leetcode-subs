class Solution {
public:
    string freqAlphabets(string s) 
    {
        int n=s.size();
        string x="";
        int i=0;
        for( i=0;i<n-1;){
            if(s[i+2]=='#')
            {
                int t=stoi(s.substr(i, 2));
                x+=(char)(96+t);
                i+=3;
            }
            else{
                int t=stoi(s.substr(i, 1));
                x+=(char)(96+t);
                i+=1;                
            }
        }
        if(i!=(n)){
            for(int j=i;j<n;j++){
                int t=stoi(s.substr(j, 1));
                x+=(char)(96+t);
  
            }
        }
            
        return x;
        
    }
};
