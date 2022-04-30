class Solution {
public:
      unordered_map< string , bool > umap;
 
  int d[ 102 ];
    
 int recur( string o, int len , int index )
    {
         string t1;
     
        if( len == o.length() ) return 1;
     
        if ( index >= o.length() ) return 0;
     
        // pick 1

        // memoization
     
        if(  d[ index ] > 0 ) return d[ index ];
    
        int take_one  = 0 , take_two = 0;
        
        t1 += o[ index ];
     
        if( umap[ t1 ] ) take_one = recur( o , len + 1 , index + 1 );
     
        // pick 2
        
        t1 += o[ index + 1 ];
     
        if( umap[ t1 ])  take_two = recur( o , len + 2 , index + 2 );
      

        return d[ index ] =  take_one + take_two;
    }
    
    int numDecodings(string s) {
  memset( d , -1 , sizeof( d ));
  string temp = "";
        
  for(int i=0;i<26;i++)
  	 umap[ to_string( i+1 )] = true;
  
  return recur( s , 0 , 0 ) ;
    }
};
