class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        ret = strs[0]
        maxlen = len(strs[0])
        for i in range(1, len(strs)):
            if(maxlen==0):return ""
            if(strs[i][:maxlen]!=ret):
                for j in range(maxlen):
                    if(strs[i][:(maxlen)]==ret[:(maxlen)]):
                        ret = ret[:(maxlen)]
                        break
                    maxlen = maxlen-1

        return ret[:maxlen]
        