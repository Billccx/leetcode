#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int len=words.size();
        unordered_map<string,int> ump;
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                if(
                    words[i].length()<=words[j].length() 
                    && words[i]==words[j].substr(0,words[i].length())
                ){
                    ump[words[i]]++;
                }
            }
        }

        vector<int> ans;

        for(int i=0;i<len;i++){
            int cnt=0;
            for(int j=1;j<=words[i].length();j++){
                string temp=words[i].substr(0,j);

                if(ump.count(temp)){
                    cnt+=ump[temp];
                }
                else{
                    int newcnt=0;
                    for(int k=0;k<len;k++){
                        if(temp==words[k].substr(0,j)){
                            cnt++;
                            newcnt++;
                        } 
                    }
                    ump[temp]=newcnt;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<string> words={"qtcqcmwcin","vkjotbrbzn","eoorlyfche","eoorlyhn","eoorlyfcxk","qfnmjilcom","eoorlyfche","qtcqcmwcnl","qtcqcrpjr"};
    vector<int> result=s.sumPrefixScores(words);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<' ';
    }
    cout<<endl;
}