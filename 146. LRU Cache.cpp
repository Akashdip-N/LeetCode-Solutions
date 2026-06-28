/*
    https://leetcode.com/problems/lru-cache
*/
/*
    Solution Approach:- Using Doubly Linked List and Hash Map

    Time Complexity: O(1)
    Space Complexity: O(N)
    N = capacity of the cache

    Explanation:-
        * We have to implement LRU cache, which means we have to keep track of the following:-
            i. The most recently used element
            ii. The least recently used element
        * To achieve this, we are using doubly linked list and hash map.
        * The doubly linked list will keep track of the order of the elements,
            with the most recently used element at the right end and
                the least recently used element at the left end.
        * The hash map will keep track of the key-value pairs,
            with the key being the key of the element and
                the value being the pointer to the node in the doubly linked list.

        INSERTING ELEMENT:-
        * DOUBLY LINKED LIST:- Inserting the new node at the 2nd position from the right end of the doubly linked list

        DELETING ELEMENT:-
        * DOUBLY LINKED LIST:- Deleting the node from the left end of the doubly linked list
        * HASH MAP:- Deleting the key-value pair from the hash map
*/
class LRUCache {
private:
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    Node* left;
    Node* right;
    unordered_map<int, Node*> cache;

public:
    LRUCache(int c) {
        capacity = c;

        left = new Node(0, 0);
        right = new Node(0, 0);

        left->next = right;
        right->prev = left;
    }

    // Removing node from List
    void remove(Node* node) {
        Node* prev_node = node->prev;
        Node* next_node = node->next;

        prev_node->next = next_node;
        next_node->prev = prev_node;
    }

    // Adding node to the right (Most Recently Used)
    void insert(Node* node) {
        Node* prev_node = right->prev;
        Node* next_node = right;

        prev_node->next = node;
        node->prev = prev_node;
        node->next = next_node;
        next_node->prev = node;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
            delete cache[key];
        }

        cache[key] = new Node(key, value);
        insert(cache[key]);

        // Removing the least recently used element if the cache exceeds its capacity
        if (cache.size() > capacity) {
            Node* lru = left->next;
            remove(lru);

            cache.erase(lru->key);
            delete lru;
        }
    }
};
