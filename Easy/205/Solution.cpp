class Solution {
public:
    bool isIsomorphic(string s, string t) {
       int map[256];
        memset(map,-1,sizeof(map));
        vector<bool>marked(256,false);
        
        for(int i=0;i<s.size();i++){
           //Check for the first character is mapped or not
            if(map[s[i]]==-1){
                
        
            //We check in marked array for the second string character 
            // because its one on one mapping it is very crucial step
            // Consider example badc, aagf  in first iteration it is mapped from b->a,means a can be replaced with b and viceversa,now we check in second iteration a ->a ,but we checked that marked[a] is true this means these are not isomorphism
          
		  
		  if(marked[t[i]]==true)
                  return false;
              
              marked[t[i]] =true;
              map[s[i]] = t[i];
              
          }
         //if already mapped then we check if its value is same or not
         else{
            if(map[s[i]] !=t[i])
                return false;
         }
            
        }
                
        return true;
    }
};
