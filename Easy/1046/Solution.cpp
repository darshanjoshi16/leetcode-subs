class Solution 
{
public:
    int lastStoneWeight(vector<int>& s) 
    {
        //it is creating the function of the heap will sort the vector
         make_heap(s.begin(), s.end());
        
        //it will run the loop untill it is fully traversed
         while (s.size() > 1) {
             
            //it will add the element into heap
            int x = s.front();
            pop_heap(s.begin(), s.end());
            s.pop_back();
            
            int y = s.front();
            pop_heap(s.begin(), s.end());
            s.pop_back();
            
            if (x == y) continue;
            
            s.push_back(abs(x - y));
            push_heap(s.begin(), s.end());
        }
        
        return s.size() ? s.front() : 0;
    }
};
