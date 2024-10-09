class Solution {
public:
    bool isPalindrome(string s) {
        int n  = s.size();
        int l = 0, r = n-1;
        while(!(tolower(s[l])>='a' && tolower(s[l])<='z'||s[l]<='9'&& s[l]>='0')&& l<(n-1))l++;
        while(!(tolower(s[r])>='a' && tolower(s[r])<='z'||s[r]<='9'&& s[r]>='0')&& r>0)r--;

        while(l<=r&&l<n&&r>=0){
            while(!(tolower(s[l])>='a' && tolower(s[l])<='z'||s[l]<='9'&& s[l]>='0')&& l<(n-1))l++;
            while(!(tolower(s[r])>='a' && tolower(s[r])<='z'||s[r]<='9'&& s[r]>='0')&& r>0)r--;
            if(tolower(s[l])!=tolower(s[r]))return 0;
            l++;
            r--;
        }
        return 1;
    }
};