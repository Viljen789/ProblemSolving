class Solution:
    def replaceDigits(self, s: str) -> str:
        for (i, c) in enumerate(s):
            if(i&1):
                s = s[:i] + chr(ord(s[i-1])+int(c)) + s[i+1:]
        return s


        