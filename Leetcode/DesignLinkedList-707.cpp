#include <iostream>
using namespace std;

class MyLinkedList {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };

    ListNode* head;
    ListNode* tail; // Added tail pointer for O(1) tail access
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr; // initialize tail
        size = 0;
    }

    int get(int index) {
        if (index > size - 1) {
            return -1;
        }
        ListNode* curr = head;
        while (curr && index > 0) {
            curr = curr->next;
            index--;
        }
        int res;
        if (index == 0 && curr != nullptr) {
            res = curr->val;
        }
        return res;
    }

    void addAtHead(int val) {
        ListNode* temp = new ListNode(val, head);
        head = temp;
        if (size == 0) {
            tail = temp; // update tail if list was empty
        }
        size++;
    }

    void addAtTail(int val) {
        ListNode* temp = new ListNode(val);
        if (head == nullptr) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index == size) { // insert at tail
            addAtTail(val);
            return;
        }
        if (index == 0) {
            addAtHead(val);
            return;
        }
        ListNode* curr = head;
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }
        ListNode* temp = new ListNode(val, curr->next);
        curr->next = temp;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index >= size || size == 0) {
            return;
        }
        size--;
        if (index == 0) {
            head = head->next;
            if (size == 0) tail = nullptr;
            return;
        }
        ListNode* curr = head;
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }
        if (curr->next == tail) {
            tail = curr; // update tail if deleting last node
        }
        curr->next = curr->next->next;
    }


    // Added for testing: prints the list elements.
    void printList() {
        ListNode* curr = head;
        cout << "[";
        while (curr) {
            cout << curr->val;
            curr = curr->next;
            if (curr)
                cout << ", ";
        }
        cout << "]";
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

// Modified test function for improved input output error reporting.
void testLinkedList() {
    cout << "\n--- Testing MyLinkedList ---\n";
    MyLinkedList list;
    auto assertEqual = [&](int testNum, int value, int expected) {
        if (value != expected) {
            cout << "Test " << testNum << " Failed: Expected " << expected << ", got " << value << "\n"
                 << "List state: ";
            list.printList();
            cout << "\n";
        } else {
            cout << "Test " << testNum << " Passed.\n";
        }
    };

    // Test addAtHead
    list.addAtHead(10);
    assertEqual(1, list.get(0), 10);

    // Test addAtTail
    list.addAtTail(20);
    assertEqual(2, list.get(1), 20);

    // Test addAtIndex: inserting 15 at index 1.
    list.addAtIndex(1, 15);
    assertEqual(3, list.get(0), 10);
    assertEqual(4, list.get(1), 15);
    assertEqual(5, list.get(2), 20);
    
    // Test get returns proper value.
    int val = list.get(1);
    assertEqual(6, val, 15);

    // Test deleteAtIndex: delete index 1.
    list.deleteAtIndex(1);
    assertEqual(7, list.get(0), 10);
    assertEqual(8, list.get(1), 20);
    // Check that out-of-bound index returns -1.
    assertEqual(9, list.get(2), -1);

    // Test invalid get index.
    val = list.get(100);
    assertEqual(10, val, -1);

    cout << "--- MyLinkedList tests completed ---\n";
}

int main() {
    testLinkedList();
    return 0;
}