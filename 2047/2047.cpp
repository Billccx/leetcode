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

/*

更好的字符串分割写法
int countValidWords(string sentence) {
        int n = sentence.length();
        int l = 0, r = 0;
        int ret = 0;
        string_view slice(sentence);
        while (true) {
            while (l < n && sentence[l] == ' ') {
                l++;
            }
            if (l >= n) {
                break;
            }
            r = l + 1;
            while (r < n && sentence[r] != ' ') {
                r++;
            }
            if (isValid(slice.substr(l, r - l))) { // 判断根据空格分解出来的 token 是否有效
                ret++;
            }
            l = r + 1;
        }
        return ret;
    }

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/number-of-valid-words-in-a-sentence/solution/ju-zi-zhong-de-you-xiao-dan-ci-shu-by-le-hvow/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/