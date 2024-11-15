class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        
        for(int i = 0; i < asteroids.size(); i++) {
            int cur = asteroids[i];
            if(cur < 0) {  // Asteroid moving left
                bool will_survive = true;
                
                while(!st.empty() && st.top() > 0) {  // Check collisions with right-moving asteroids
                    if(st.top() < abs(cur)) {  // Current asteroid destroys the one in stack
                        st.pop();
                    }
                    else if(st.top() == abs(cur)) {  // Both asteroids destroy each other
                        st.pop();
                        will_survive = false;
                        break;
                    }
                    else {  // Current asteroid is destroyed
                        will_survive = false;
                        break;
                    }
                }
                
                if(will_survive) {
                    ans.push_back(cur);
                }
            }
            else {  // Asteroid moving right
                st.push(cur);
            }
        }
        
        // Add remaining right-moving asteroids
        vector<int> temp;
        while(!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }
        
        // Add them in correct order
        for(int i = temp.size() - 1; i >= 0; i--) {
            ans.push_back(temp[i]);
        }
        
        return ans;
    }
};