class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> um;
        int n = arr.size();
        for(int i = 0; i<n; i++){
            if(um[arr[i]])return true;
            
            um[arr[i]*2] = 1;
            if(!(arr[i]&1))um[arr[i]/2] = 1;
        }
        return false;
        
    }
};