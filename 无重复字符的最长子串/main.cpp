//
//  main.cpp
//  无重复字符的最长子串
//
//  Created by Dynasty Dream on 2023/4/3.
//

#include <iostream>
using  namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string midStr = "";
        unsigned long maxNum = 0;
        for(int i = 0 ; i< s.size() ; i++){
            bool endFalse = true;
            for(int j = 0; j<midStr.size() ; j++){
                if(s[i] == midStr[j]){
                    if(maxNum < midStr.size()){
                        maxNum = midStr.size();
                    }
                    midStr = midStr.substr(j + 1 , midStr.size() - j);
                    midStr = midStr + s[i];
                    endFalse = false;
                    break;
                }
            }
            if(endFalse == true){
                midStr = midStr + s[i];
            }
        }
        if(maxNum < midStr.size()){
            maxNum = midStr.size();
        }
        return (int)maxNum;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    Solution *so = new Solution ;
    int result = so->lengthOfLongestSubstring("bbbbbb");
    cout << result <<endl;
    return 0;
}
