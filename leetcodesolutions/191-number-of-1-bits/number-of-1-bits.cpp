class Solution {
public:
    int hammingWeight(int n) {
        long long k = 1;
        int tot = 0;
        while(k<=n){
            if(k&n)tot++;
            k<<=1;
        }
        return tot;
    }
};