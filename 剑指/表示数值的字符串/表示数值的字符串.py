class Solution:

    def checkPure(self,st:str) -> bool:
        if len(st)==0: return False
        for item in st:
            if item<'0' or item>'9': return False
        return True

    def checkInt(self,st: str) -> bool:
        s=st
        if(len(s)==0):return False
        if s[0]=='+' or s[0]=='-' or (s[0]>='0' and s[0]<='9'):
            if s[0]=='+' or s[0]=='-':
                s=s[1:]
            if s=="":return False
            for item in s:
                if item<'0' or item>'9':
                    return False
            return True
        else:
            return False

    def checkIntorFloat(self,st:str)->bool:
        s=st
        if(len(s)==0): return False
        if self.checkInt(s): return True
        if s[0]=='+' or s[0]=='-':
            s=s[1:]
        s=s.split('.')        
        if len(s)>2:
            return False
        
        if len(s)==2:
            return (self.checkPure(s[0]) and s[1]=="") or (self.checkPure(s[1]) and s[0]=="") or (self.checkPure(s[0]) and self.checkPure(s[1]))
        
        elif len(s)==1:
            return self.checkInt(s[0])
        
        else: return False

        

    def isNumber(self, s: str) -> bool:
        s=s.strip()
        p=-1
        for i in range(len(s)):
            if s[i]=='e'or s[i]=='E':
                p=i
                break
        if p!=-1:
            return self.checkIntorFloat(s[0:p]) and self.checkInt(s[p+1:])
        else:
            return self.checkIntorFloat(s)
