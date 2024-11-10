class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int cur = capacity, tot = 0;
        for(int i = 0; i<n; i++){
            if(cur>=plants[i]){
                tot++;
                cur-=plants[i];
            }
            else{
                tot+=2*(i)+1;
                cur = capacity-plants[i];
            }
            cout << tot << endl;
        }
        return tot;
    }
};
/*
1
3
5
7
9 

_-0-1-2-3-4-5-6-7


*/