int odd(string s, int i){
    int l = i, r = i;
    int tot = 0;
    while(l>=0 && r<=(s.size()-1)){
        if(s[l--]==s[r++])tot++;
        else break;
    }
    return tot;
}
int even(string s, int i){
    int l = i-1, r = i;
    int tot = 0;
    while(l>=0 && r<(s.size())){
        if(s[l--]==s[r++])tot++;
        else break;
    }
    return tot;
}

class Solution {
public:
    int countSubstrings(string s) {
        int tot = 0;
        for(int i = 0; i<s.size(); i++){
            tot += even(s, i);
            tot += odd(s, i);
        }
        return tot;

    }
};