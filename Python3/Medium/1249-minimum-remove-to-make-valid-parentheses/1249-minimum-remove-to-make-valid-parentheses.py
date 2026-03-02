class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        pars = []
        count = 0
        for (i, c) in enumerate(s):
            if c  in ("(", ")"):
                pars.append((c, i))
            
        i = 0
        while(i<len(pars)):
            p = pars[i]
            if(p[0]==")"):
                if(i != 0 and pars[i-1][0]=="("):
                    pars.pop(i)
                    pars.pop(i-1)
                    i-=2
            i+=1

        for i in pars[::-1]:
            s = s[:i[1]]+s[i[1]+1:]
        return s


        

        