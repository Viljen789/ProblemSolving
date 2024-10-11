class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1= version1
        v2= version2
        l1 = v1.split(".")
        l2 = v2.split(".")
        if(len(l1)<len(l2)):
            for i in range(len(l2)-len(l1)):
                l1.append("0")
        else:
            for i in range(len(l1)-len(l2)):
                l2.append("0")

        print(l1, l2)

        for i in range(min(len(l1), len(l2))):
            i1 = int(l1[i])
            i2 = int(l2[i])
            if i1>i2:return 1
            if i2>i1:return -1

        
        return 0

        
