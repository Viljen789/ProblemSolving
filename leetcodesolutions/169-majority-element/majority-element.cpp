#define mp make_pair
#define f first
#define s second
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        pair<int, int> p = mp(0, 0);
        for(int i = 0; i<n; i++){
            if(nums[i] == p.f)p.s++;
            else p.s--;
            if(p.s<=0){
                p.f = nums[i];
                p.s = 1;
            }
            cout << p.f << "  "<< p.s << endl;
        }
        return p.f;

    }
};