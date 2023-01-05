class Solution {
public:
    int maxProduct(vector<string>& words) {
        int l=words.size();
        vector<int> len,key;
        for(int i=0;i<l;i++){
            int t=words[i].length();
            len.push_back(t);
            int temp=0;
            for(int j=0;j<t;j++){
                temp=temp|(1<<(words[i][j]-'a'));
            }
            key.push_back(temp);
        } 

        int ans=0;
        for(int i=0;i<l;i++){
            for(int j=i+1;j<l;j++){
                if((key[i]&key[j])==0){
                    ans=max(ans,len[i]*len[j]);
                }
            }
        }

        return ans;
    }
};