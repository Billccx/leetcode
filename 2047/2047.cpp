#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int isNumber(char c){
        if(c>='0' && c<='9') return 1;
        else return 0;
    }

    int isChar(char c){
        if(c>='a'&& c<='z') return 1;
        else return 0;
    }

    int isPunc(char c){
        if(c=='!'||c==','||c=='.') return 1;
        else return 0;
    }

    vector<string> split(string s){
        int len=s.length(),start=0,end=0;
        //cout<<"len:"<<len<<endl;
        vector<string> v;
        while(end<=len){
            if(end==len){
                //cout<<start<<','<<end<<endl;
                if(end!=start) v.push_back(s.substr(start,end-start));
                break;
            }
            if(s[end]==' '){
                //cout<<start<<','<<end<<endl;
                if(end!=start) v.push_back(s.substr(start,end-start));
                while(end<len && s[end]==' ') end++;
                start=end;
            }
            else{
                end++;
            }
        }
        return v;
    }


    int countValidWords(string sentence) {
        vector<string> v=split(sentence);
        // for(auto item: v){
        //     cout<<item<<endl;
        // }
        int cnt=0;
        for(auto item : v){
            int isValid=1,has_=0;
            for(int i=0;i<item.length();i++){
                if(isNumber(item[i])){
                    isValid=0;
                    break;
                }
                if(isPunc(item[i])&& i!=item.length()-1){
                    isValid=0;
                    break;
                }
                if(item[i]=='-' ){
                    //cout<<item.length()<<"    "<<i<<item[i-1]<<item[i+1]<<endl;
                    if(has_==0 && i-1>=0 && i+1<item.length() && isChar(item[i-1]) && isChar(item[i+1])){
                        has_=1;
                    }
                    else{
                        isValid=0;
                        break;
                    }
                }
            }
            if(isValid) cnt++;
            //cout<<item<<':'<<isValid<<endl;
        }
        return cnt;
    }
};

int main(){
    Solution s;
    string sentence = " o6 t";
    int result=s.countValidWords(sentence);
    cout<<result<<endl;
}