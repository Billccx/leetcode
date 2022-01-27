#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countValidWords(string sentence) {
        int cnt=0;
        int hasNum=0,has_=0,hasPunctuation=0;
        int isValid=1;
        int len=sentence.length();
        int i=0;
        while(i<len){
            if(isValid==0 && sentence[i]!=' '){
                i++;
            }
            else if(sentence[i]==' '){
                hasNum=0;
                has_=0;
                hasPunctuation=0;
                if(isValid) cnt++;
                isValid=1;
                while(i+1<len && sentence[i]==' ') i++;
            }
            else if(sentence[i]>='0' &&sentence[i]<='9'){
                hasNum=1;
                isValid=0;
                i++;
            }
            else if(sentence[i]=='-'){
                if(has_==0 && i-1>0 && i+1<len && sentence[i-1]>='a' &&sentence[i-1]<='z' && sentence[i+1]>='a' &&sentence[i+1]<='z'){
                    has_=1;
                }
                else{
                    isValid=0;
                }
                i++;
            }
            else if(sentence[i]=='!' && sentence[i]==',' && sentence[i]=='.'){
                if(hasPunctuation=0 && ((i+1>=len && sentence[i-1]>='a' &&sentence[i-1]<='z')||(i+1<len && sentence[i+1]==' ' && sentence[i-1]>='a' &&sentence[i-1]<='z'))){
                    hasPunctuation+=1;
                }
                else{
                    isValid=0;
                }
                i++;
            }
            else{
                i++;
            }
        }
        return cnt;
    }
};

int main(){
    Solution s;
    string sentence = "alice and  bob are playing stone-game10";
    int result=s.countValidWords(sentence);
    cout<<result<<endl;
}