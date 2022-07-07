#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
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
    ListNode* reverseList(ListNode* head) {

    }
};


int main(){
    struct ListNode* p=new struct ListNode(0);
    struct ListNode* head=p;
    for(int i=1;i<6;i++){
        p->next=new struct ListNode(i);
        p=p->next;
    }

}