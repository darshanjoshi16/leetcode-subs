class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        //created a stack using STL
            stack<int>st;
    
        //created a ordered Map using STL
        map<int,int>nextGreater;
    
        //intialize the size
        int n=nums2.size();
    
        //giving the value to the map which is initial
        nextGreater[nums2[n-1]]=-1;
    
        //pushing the value into stack
        st.push(nums2[n-1]);
    
        //running the loop
        for(int i=n-2;i>=0;i--)
        {
        
            //checking when the stack is not empty and top of stack is less than the nums2 i'th index value, then pop the value
            while(!st.empty() && st.top()<nums2[i]){st.pop();}
        
            //if the stack is empty, return the -1
            if(st.empty()){nextGreater[nums2[i]]=-1;}
        
            //else the map value is given to  stack top
            else{nextGreater[nums2[i]]=st.top();}
        
            //pushing the value into stack
            st.push(nums2[i]);
    }
        //creating the resultant vector and printing the answer
    vector<int>ans;
    int m=nums1.size();
    for(int i=0;i<m;i++)
    {
        ans.push_back(nextGreater[nums1[i]]);
    }
    
    return ans;
    
    }
};
