class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char k;
        for(int i = 0; i<s.size(); i++){
            k = s[i];
            if((k=='(') || (k=='[') || (k=='{'))st.push(k);
            else if(st.empty())return 0;
            switch(k){
                case ')':
                    if(st.top()=='(')st.pop();
                    else return 0;
                    break;
                case ']':
                    if(st.top()=='[')st.pop();
                    else return 0;
                    break;
                case '}':
                    if(st.top()=='{')st.pop();
                    else return 0;
                    break;
            }
        }
        return(st.empty());

    }
};