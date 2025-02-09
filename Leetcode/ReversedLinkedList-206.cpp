#include <iostream>
#include <stack>
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
public:
    // Iterative approach
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *prev = nullptr;
        ListNode *curr = head;

        while (curr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Recursive approach
    ListNode *reverseListRecursive(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *rest = reverseListRecursive(head->next);
        head->next->next = head;
        head->next = nullptr;

        return rest;
    }
};

// Utility functions
ListNode *createLinkedList(const initializer_list<int> &values)
{
    if (values.size() == 0)
        return nullptr;
    ListNode *head = new ListNode(*values.begin());
    ListNode *current = head;
    for (auto it = values.begin() + 1; it != values.end(); ++it)
    {
        current->next = new ListNode(*it);
        current = current->next;
    }
    return head;
}

void printList(ListNode *head, string message = "")
{
    if (!message.empty())
        cout << message << ": ";
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

void freeList(ListNode *head)
{
    while (head)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    Solution solution;

    cout << "\nTest 1: Iterative approach" << endl;
    ListNode *test1 = createLinkedList({1, 2, 3, 4, 5});
    printList(test1, "Original");
    ListNode *result1 = solution.reverseList(test1);
    printList(result1, "Reversed");
    freeList(result1);

    cout << "\nTest 2: Recursive approach" << endl;
    ListNode *test2 = createLinkedList({1, 2, 3, 4, 5});
    printList(test2, "Original");
    ListNode *result2 = solution.reverseListRecursive(test2);
    printList(result2, "Reversed");
    freeList(result2);

    // Test Case 3: Single node
    cout << "\nTest 3: Single node" << endl;
    ListNode *test3 = createLinkedList({1});
    printList(test3, "Original");
    ListNode *result3 = solution.reverseList(test3);
    printList(result3, "Reversed");
    freeList(result3);

    // Test Case 4: Empty list
    cout << "\nTest 4: Empty list" << endl;
    ListNode *test4 = nullptr;
    printList(test4, "Original");
    ListNode *result4 = solution.reverseList(test4);
    printList(result4, "Reversed");

    // Test Case 5: Two nodes
    cout << "\nTest 5: Two nodes" << endl;
    ListNode *test5 = createLinkedList({1, 2});
    printList(test5, "Original");
    ListNode *result5 = solution.reverseList(test5);
    printList(result5, "Reversed");
    freeList(result5);

    return 0;
}