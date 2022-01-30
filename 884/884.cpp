#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> rare;
        unordered_map<string,int> ump;
        int l=0,r=0,len=s1.length();
        while(r<len){
            while(r<len && s1[r]!=' ') r++;
            ump[s1.substr(l,r-l)]++;
            l=r+1;
            r=l;
        }

        len=s2.length();
        l=r=0;
        while(r<len){
            while(r<len && s2[r]!=' ') r++;
            ump[s2.substr(l,r-l)]++;
            l=r+1;
            r=l;
        }

        for(unordered_map<string,int>::iterator p=ump.begin();p!=ump.end();p++){
            if(p->second==1){
                rare.emplace_back(p->first);
            }
        }
        return rare;
    }
};

int main(){
    Solution s;
    string s1="this apple is sweet",s2="this apple is sour";
    vector<string> result=s.uncommonFromSentences(s1,s2);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
}


/*

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freq;
        
        auto insert = [&](const string& s) {
            stringstream ss(s);
            string word;
            while (ss >> word) {
                ++freq[move(word)];
            }
        };

        insert(s1);
        insert(s2);

        //遍历map
        vector<string> ans;
        for (const auto& [word, occ]: freq) {
            if (occ == 1) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/uncommon-words-from-two-sentences/solution/liang-ju-hua-zhong-de-bu-chang-jian-dan-a8bmz/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/
