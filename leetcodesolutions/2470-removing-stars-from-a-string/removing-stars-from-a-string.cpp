class Solution {
public:
    string removeStars(string s) {

        stack<char> sq;
        for(int i = 0; i<s.size(); i++){
            if(s[i]=='*')sq.pop();
            else sq.push(s[i]);
        }
        stack<char> ans;
        while(!sq.empty()){
            ans.push(sq.top());
            sq.pop();
        }
        string a = "";
        while(!ans.empty()){
            a+=ans.top();
            ans.pop();
        }
        return a;
    }
};