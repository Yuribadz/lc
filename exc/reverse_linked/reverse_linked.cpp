#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void insert(int val)
    {
        ListNode *cursor = this;
        while (cursor->next)
        {
            cursor = cursor->next;
        }
        ListNode *temp = new ListNode();
        temp->next = nullptr;
        temp->val = val;
        cursor->next = temp;
    }
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode* cursor = head;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        while(cursor)
        {
            next = cursor->next;
            cursor->next = prev;
            prev = cursor;
            cursor = next;
        }
        return prev;
    }
};

int main()
{
    ListNode* node = new ListNode();
    for(int i = 1; i < 10; ++i)
    {
        node->insert(i);
    }
    
    ListNode* cursor = Solution().reverseList(node);
    while (cursor)
    {
        std::cout<< cursor->val << std::endl;
        cursor = cursor->next;
    }
    
    return 0;
}