// Jobbe innenfra og ut. Stack? QUeue?
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        int n = tokens.size();
        int tot = 0;
        int a = 0, b = 0;
        for(int i = 0; i<n; i++){
            if(tokens[i]=="+"){
                a = stoi(s.top());
                s.pop();
                b = stoi(s.top());
                s.pop();
                s.push(to_string(a+b));
            }
            else if(tokens[i]=="-"){
                a = stoi(s.top());
                s.pop();
                b = stoi(s.top());
                s.pop();
                s.push(to_string(b-a));
            }
            else if(tokens[i]=="*"){
                a = stoi(s.top());
                s.pop();
                b = stoi(s.top());
                s.pop();
                s.push(to_string(a*b));
            }
            else if(tokens[i]=="/"){
                a = stoi(s.top());
                s.pop();
                b = stoi(s.top());
                s.pop();
                s.push(to_string(b/a));
            }else s.push(tokens[i]);
            cout << s.top()<<endl;
        }
        return stoi(s.top());
    }
};