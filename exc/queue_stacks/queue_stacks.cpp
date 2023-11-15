#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>

class MyQueue
{
public:
    void push(int value)
    {
        m_stack_push.push(value);
    }

    void move_to_pop()
    {
        if (m_stack_pop.empty())
        {
            while (!m_stack_push.empty())
            {
                m_stack_pop.push(m_stack_push.top());
                m_stack_push.pop();
            }
        }
    }
    int pop()
    {
        int ret = peek();
        m_stack_pop.pop();
        return ret;
    }

    int peek()
    {
        if(m_stack_pop.empty() && m_stack_push.empty())
        {
            return INT_MIN;
        }
        move_to_pop();
        return m_stack_pop.top();
    }

    bool empty()
    {
        move_to_pop();
        return m_stack_pop.empty();
    }

private:
    std::stack<int> m_stack_pop;
    std::stack<int> m_stack_push;
};

int main()
{
    MyQueue que;
    que.push(10);
    que.push(20);
    std::cout << que.pop() << std::endl;
    std::cout << que.pop() << std::endl;
    return 0;
}