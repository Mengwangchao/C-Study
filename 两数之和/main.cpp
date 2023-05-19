//
//  main.cpp
//  两数之和
//
//  Created by Dynasty Dream on 2023/4/3.
//
#include <vector>
#include <map>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        
        for(int i = 0 ; i < nums.size(); i++){
            for(int j = i+1 ; j < nums.size(); j++){
                if(nums[i] + nums[j] == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
        }
        return result;
    }
};
class rightSolution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
          map<int,int>mp;//mp只用来当做一个hash表，第一个保存nums【i】，第二个保存i;
          map<int,int>::iterator it;
          for(int i=0;i<nums.size();i++){
            it=mp.find(target-nums[i]);
            if(it!=mp.end()){
              return {i,it->second};
            }
            else mp[nums[i]]=i;
          }
      return {};
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    rightSolution *s = new rightSolution;
    vector<int> nums{2,7,11,15};
    vector<int> result = s->twoSum(nums, 9);
    for( auto i:result){
        cout<< i <<endl;
    }
    return 0;
}
