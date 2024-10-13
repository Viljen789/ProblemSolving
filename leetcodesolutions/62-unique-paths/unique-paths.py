
def fact(a):
    if(a < 2):return 1
    return a*fact(a-1)



def comb(a,b):
    tot = 1
    for i in range(b-1):
        tot*=(a+b-2-i)
    return tot/fact(b-1)

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        if(min(n, m)<=1):return(1)
        if(min(n, m)<=2):return(max(n, m))
        return int(comb(max(m, n), min(m, n)))
        