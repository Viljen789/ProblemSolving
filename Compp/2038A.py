def solve():
    num = int(inp.readline())
    l = (inp.readline().split(" "))
    l = [int(x) for x in l]
    for i in range(num-1):
        if not ((abs(l[i]-l[i+1])==5 or abs(l[i]-l[i+1])==7)):
            return False
    return True

inp = open("/Users/vilje/Desktop/Studie/ProblemSolving/Compp/input 2.txt", "r")
out = open("/Users/vilje/Desktop/Studie/ProblemSolving/Compp/output 2.txt", "w")
tc = int(inp.readline())
for i in range(tc):
    if(solve()):
        out.write("YES\n")
    else: out.write("NO\n")




"""
8
2
114 109
2
17 10
3
76 83 88
8
38 45 38 80 85 92 99 106
5
63 58 65 58 65
8
117 124 48 53 48 43 54 49
5
95 102 107 114 121
10
72 77 82 75 70 75 68 75 68 75
"""