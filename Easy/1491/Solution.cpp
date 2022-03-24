class Solution {
public:
    double average(vector<int>& salary) {
        
        //it will sort the vector
        sort(salary.begin(),salary.end());
            
        //the initialization of sum variable which will store sum of salaries in array
        double sum = 0;
        
        for(int i=1; i<salary.size()-1;i++)
        {
            //this will add the salaries except the lowest and highest
            sum += salary[i];
        }
        
        //it will return the average salary after removing the lowest and highest
        return sum / (salary.size()-2);
        
    }
};
