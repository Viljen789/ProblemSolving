class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26);
        if(s.size()!=t.size())return false;
        for(int i = 0; i<s.size(); i++){
            v[s[i]-'a']++;
            v[t[i]-'a']--;
        }
        for(int i = 0; i<v.size(); i++){
            if(v[i]!=0)return 0;
        }
        return 1;
    }
};