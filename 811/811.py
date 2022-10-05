class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        map={}
        for item in cpdomains:
            item=item.split(' ')
            times=item[0]
            add=item[1].split('.')
            l=len(add)-1
            s=""
            while l>=0:
                if l==len(add)-1:
                    s=add[l]+s
                else:
                    s=add[l]+'.'+s

                if s in map:
                    map[s]+=int(times)
                else:
                    map[s]=int(times) 
                l-=1
        ans=[]
        for k in map:
            res=str(map[k])+' '+k
            ans.append(res)
        return ans
