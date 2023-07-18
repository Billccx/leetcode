class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        words=sentence.split(' ')
        ans=[]
        dic={}
        for item in dictionary:
            dic[item]=True
        for item in words:
            l=len(item)
            isFind=False
            for i in range(1,l+1):
                if dic.get(item[0:i],False):
                    ans.append(item[0:i])
                    isFind=True
                    break
            if not isFind:
                ans.append(item)
        s=''
        for i in range(len(ans)):
            if i!=len(ans)-1:
                s+=ans[i]+' '
            else:
                s+=ans[i]
        return s
