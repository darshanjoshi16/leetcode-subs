class Solution {
public:
    string convert(string s, int numRows) {
        string results;
	//zero rows
    if (numRows == 0) return results;
	//one row
    if (numRows == 1) return s;

	 //creating rows
    for(int i=0; i< numRows && i<s.length(); i++){
		
		//distance to next full column
        int distance = (numRows-1)*2;
		
        //distance to next diagonal-column number
		int gap = ((numRows-1)*2)-(i*2);
		
        results = results + s[i];
        for (int j=i; j+gap <s.length(); j++){

            if (gap > 0 )results = results + s[gap+j];
            if (gap ^ distance && distance+j < s.length())results = results + s[distance+j];
            j+=distance-1;
			
		}

    }
     return results;

    }
};
