#include <iostream>
#include <vector>
#include <string>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void insert(ListNode *head, int val)
    {
        ListNode *cursor = head;
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
    bool hasCycle(ListNode *head)
    {
        ListNode *fast, *slow;
        fast = slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};

int main()
{
    ListNode *list1 = new ListNode();
    list1->insert(list1, 5);
    list1->next->next = list1;
    ListNode *iter;
    std::cout << Solution().hasCycle(list1) << std::endl;
    // for (int i = 0; i < 10; ++i)
    // {
    //     iter = list1->next;
    //     delete list1;
    //     list1 = iter;
    // }
    return 0;
}