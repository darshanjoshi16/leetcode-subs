class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        //created a integer list 
         list<int> lst;
    
        //running a loop for number vector to add num elements into the list
        for(auto x : nums) 
        {
            lst.push_back(x);
        }
        
    //running the logic for rotating for the value of k
    while(k--){
        //the value which is at back will be push to one position front
        lst.push_front(lst.back());
        //it will pop the back element
        lst.pop_back();
    }
    
    //traversing the list and giving the resultant answer
    int i=0;
    for(auto x : lst) {
        nums[i++] = x;
    }

        
    }
};
