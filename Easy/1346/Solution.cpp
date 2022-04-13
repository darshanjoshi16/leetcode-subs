class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        vector<int>::iterator it = arr.begin();
        for(int i = 0; i < arr.size(); i++){
            it++;
            if(arr[i] >= 0 && binary_search(it, arr.end(), arr[i]*2))
                return true;
            else if(arr[i]<0 && binary_search(arr.begin(), it, arr[i]*2))
                return true;
        }
        return false;
    }
};
