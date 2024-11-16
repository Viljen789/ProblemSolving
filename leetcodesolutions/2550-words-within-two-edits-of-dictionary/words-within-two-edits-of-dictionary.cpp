#define pb push_back
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n = queries.size(), m = dictionary.size();
        int l = queries[0].size();
        vector<string> ans;
        for(int query = 0; query<n; query++){
            for(int dic = 0 ; dic<m; dic++){
                int diff = 0;
                for(int ch = 0; ch<l; ch++){
                    if(queries[query][ch]!=dictionary[dic][ch])diff++;
                }
                if(diff<=2){
                    ans.pb(queries[query]);
                    break;
                }
            }
        }
        return ans;
    }
};