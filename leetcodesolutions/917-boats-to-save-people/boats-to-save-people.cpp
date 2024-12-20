class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int tot = 0, l = 0, r = people.size()-1;
        while(l<=r){
            if((people[l]+people[r])>limit){
                tot++;
                r--;
            }
            else {
                tot++;
                r--;
                l++;
            }
        }
        return tot;
    }
};