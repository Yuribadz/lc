#include <iostream>
#include <vector>
#include <string>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void insert(ListNode* head, int val)
    {
        ListNode* cursor = head;
        while(cursor->next)
        {
            cursor = cursor->next;
        }
        ListNode* temp = new ListNode();
        temp->next = nullptr;
        temp->val = val;
        cursor->next = temp;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result;
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        
        if(list1->val < list2->val)
        {
            result = list1;
            list1 = list1->next;
        }
        else
        {
            result = list2;
            list2 = list2->next;
        }

        ListNode *iterator = result;
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                iterator->next = list1;
                list1 = list1->next;
            }
            else
            {
                iterator->next = list2;
                list2 = list2->next;
            }
            iterator = iterator->next;
        }
        if(!list1)
        {
            iterator->next = list2;
        }
        else{
            iterator->next = list1;
        }
        return result;
    }
};

int main()
{
    ListNode* list1 = new ListNode();
    ListNode* list2 = new ListNode();
    for(int i = 1; i < 10; ++i)
    {
        list1->insert(list1, i);
        list2->insert(list2, i);
    }
    ListNode* iter;
    ListNode* iter2;
    Solution().mergeTwoLists(list1, list2);
    for(int i = 0; i < 10; ++i)
    {
        iter = list1->next;
        delete list1;
        list1 = iter;
        iter2 = list2->next;
        delete list2;
        list2 = iter2;
    }
    return 0;
}