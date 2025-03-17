#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
private:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        ListNode dummy(0);
        ListNode *tail = &dummy;

        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;

        return dummy.next;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;

        int n = lists.size();

        while (n > 1)
        {
            int j = 0;
            for (int i = 0; i < n; i += 2)
            {
                if (i + 1 < n)
                {
                    lists[j++] = mergeTwoLists(lists[i], lists[i + 1]);
                }
                else
                {
                    lists[j++] = lists[i];
                }
            }
            n = j;
        }

        return n > 0 ? lists[0] : nullptr;
    }
};

int main()
{
    Solution sol;
    ListNode *a = new ListNode(1);
    a->next = new ListNode(4);
    a->next->next = new ListNode(5);

    ListNode *b = new ListNode(1);
    b->next = new ListNode(3);
    b->next->next = new ListNode(4);

    ListNode *c = new ListNode(2);
    c->next = new ListNode(6);

    vector<ListNode *> lists = {a, b, c};
    ListNode *result = sol.mergeKLists(lists);

    // Print the result and free memory simultaneously
    ListNode *current = result;
    while (current)
    {
        cout << current->val << " ";
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }
    cout << endl;

    return 0;
}