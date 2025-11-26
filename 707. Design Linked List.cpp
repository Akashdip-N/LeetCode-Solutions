/*
    https://leetcode.com/problems/design-linked-list
*/
/*
    Solution Approach: Using Singly Linked List

    Time Complexity: O(N)
    Space Complexity: O(1)

    N = number of nodes in the linked list

    Explanation:
        * We define a Node structure to represent each node in the linked list.
        * The MyLinkedList class maintains a
            pointer to the head of the list and the size of the list.
        * The get method retrieves the value at a specific index by traversing the list.
        * The addAtHead method adds a new node at the beginning of the list.
        * The addAtTail method adds a new node at the end of the list.
        * The addAtIndex method inserts a new node at a specific index.
        * The deleteAtIndex method removes a node at a specific index.
        * All methods handle edge cases such as invalid indices and empty lists.
*/
class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int v) : val(v), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {
        if(index < 0 || index >= size)
            return -1;

        Node* temp = head;

        while(index--)
            temp = temp->next;

        return temp->val;
    }

    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;
        size++;
    }

    void addAtTail(int val) {
        Node* node = new Node(val);
        if(!head) {
            head = node;
        } else {
            Node* temp = head;
            while(temp->next)
                temp = temp->next;

            temp->next = node;
        }

        size++;
    }

    void addAtIndex(int index, int val) {
        if(index < 0 || index > size)
            return;

        if(index == 0) {
            addAtHead(val);
            return;
        }

        Node* temp = head;
        for(int i = 0; i < index-1; i++)
            temp = temp->next;

        Node* node = new Node(val);
        node->next = temp->next;
        temp->next = node;

        size++;
    }

    void deleteAtIndex(int index) {
        if(index < 0 || index >= size)
            return;

        if(index == 0) {
            Node* del = head;
            head = head->next;
            delete del;
        } else {
            Node* temp = head;
            for(int i = 0; i < index-1; i++)
                temp = temp->next;

            Node* del = temp->next;
            temp->next = temp->next->next;

            delete del;
        }

        size--;
    }
};
