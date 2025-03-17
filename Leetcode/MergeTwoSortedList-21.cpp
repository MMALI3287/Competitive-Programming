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
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode dummy;
        ListNode *tail = &dummy;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        tail->next = list1 ? list1 : list2;
        return dummy.next;
    }
};
ListNode *createList(vector<int> arr)
{
    if (arr.empty())
        return nullptr;
    ListNode *head = new ListNode(arr[0]);
    ListNode *curr = head;
    for (int i = 1; i < arr.size(); i++)
    {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Helper function to print linked list
void printList(ListNode *head)
{
    ListNode *curr = head;
    while (curr)
    {
        cout << curr->val;
        if (curr->next)
            cout << " -> ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    Solution sol;

    // Test Case 1: Regular merge
    ListNode *list1 = createList({1, 2, 4});
    ListNode *list2 = createList({1, 3, 4});
    cout << "Test Case 1:\nList1: ";
    printList(list1);
    cout << "List2: ";
    printList(list2);
    cout << "Merged: ";
    printList(sol.mergeTwoLists(list1, list2));

    // Test Case 2: One empty list
    list1 = createList({});
    list2 = createList({1, 2, 3});
    cout << "\nTest Case 2:\nList1: (empty)\nList2: ";
    printList(list2);
    cout << "Merged: ";
    printList(sol.mergeTwoLists(list1, list2));

    // Test Case 3: Both empty lists
    list1 = createList({});
    list2 = createList({});
    cout << "\nTest Case 3:\nList1: (empty)\nList2: (empty)\nMerged: ";
    printList(sol.mergeTwoLists(list1, list2));

    // Test Case 4: Lists with different lengths
    list1 = createList({1, 3, 5, 7});
    list2 = createList({2, 4, 6});
    cout << "\nTest Case 4:\nList1: ";
    printList(list1);
    cout << "List2: ";
    printList(list2);
    cout << "Merged: ";
    printList(sol.mergeTwoLists(list1, list2));

    // Test Case 5: Lists with negative numbers
    list1 = createList({-3, -1, 2});
    list2 = createList({-2, 0, 3});
    cout << "\nTest Case 5:\nList1: ";
    printList(list1);
    cout << "List2: ";
    printList(list2);
    cout << "Merged: ";
    printList(sol.mergeTwoLists(list1, list2));

    return 0;
}