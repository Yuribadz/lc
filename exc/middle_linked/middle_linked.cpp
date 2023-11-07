#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

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
    void deleteList(struct ListNode **head_ref)
    {
        struct ListNode *current = *head_ref;
        struct ListNode *next;

        while (current != nullptr)
        {
            next = current->next;
            delete current;
            current = next;
            *head_ref = nullptr;
        }
    }
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main()
{
    ListNode *node = new ListNode();
    for (int i = 1; i < 10; ++i)
    {
        node->insert(i);
    }
    std::cout << Solution().middleNode(node)->val << std::endl;
    node->deleteList(&node);
    return 0;
}