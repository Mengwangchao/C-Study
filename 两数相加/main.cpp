//
//  main.cpp
//  两数相加
//
//  Created by Dynasty Dream on 2023/4/3.
//

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int addNum = 0;
        ListNode *num1 = l1, *num2 = l2;
        ListNode *midNode = new ListNode;
        ListNode *resultNode = midNode;
        while ((num1 != NULL || num2 != NULL) || addNum != 0) {
            int result ;
            if(num1 != NULL && num2 != NULL){
                result = num1 -> val + num2 ->val + addNum;
            }else if(num1 == NULL && num2 != NULL){
                result = num2 ->val + addNum;
            }else if(num2 == NULL && num1 != NULL){
                result = num1 ->val + addNum;
            }else{
                result = addNum;
            }
            if (result >= 10){
                addNum = 1;
                midNode ->val = result%10;
                
            }else{
                addNum = 0;
                midNode ->val = result;
            }
            midNode -> next = new ListNode;
            midNode = midNode->next;
            if (num1  != NULL){
                num1 = num1 -> next;
            }
            if (num2 != NULL){
                num2 = num2 -> next;
            }
            
        }
        midNode = resultNode;
        while (1) {
            if(midNode -> next != NULL && midNode -> next ->next == NULL){
                midNode ->next = NULL;
                break;
            }else{
                midNode = midNode ->next;
            }
        }
        return resultNode;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode *num1 = new ListNode;
    ListNode *num2 = new ListNode;
    num1->val = 2;
    num1 -> next = NULL;
    num1 ->next = new ListNode;
    num1 ->next->val = 4;
    num1 ->next ->next = new ListNode;
    num1 ->next ->next ->val = 3;
    num1 ->next ->next ->next = NULL;
    num2->val = 5;
    num2 ->next = NULL;
    num2 ->next = new ListNode;
    num2 ->next->val = 6;
    num2 ->next ->next = new ListNode;
    num2 ->next ->next ->val = 4;
    num2 ->next ->next ->next = NULL;
    Solution * solu = new Solution;
    ListNode *result = solu->addTwoNumbers(num1, num2);
    while (result !=NULL) {
        cout << result->val;
        result = result->next;
    }
    cout<< endl;
    return 0;
}
