class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v(n+1);
        for(int i = 0; i<n+1; i++){
            int k = 1;
            while(k<=i){
                if(k&i)v[i]++;
                k<<=1;
            }
        }
    return v;
    }
};