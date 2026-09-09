/*
    https://leetcode.com/problems/lru-cache
*/
/*
    Solution Approach:- Using Two Pointers and Doubly Linked List and Hash Map

    Time Complexity: O(1)
    Space Complexity: O(N)
    N = capacity of the cache

    Intuition:-
        - We have to implement LRU cache, which means we have to keep track of the following:-
            i. The most recently used element
            ii. The least recently used element
        - When we are inserting a new element into the cache,
            we have to check if the key already exists in the cache or not,
                i. if it exists, then we need to update the value of the counter for that key.
                ii. If it doesn't exists then,
                    - Checking if the capacity of the cache is full or not,
                        if it's full, then we need to remove the least recently used element
                            then we can insert the new element into the cache.
                    - Else, we can directly insert the new element into the cache,
                        and set the counter for that key to 1.
        Ex:-
            Capacity = 2
            put(1, 1) -> cache = {1=1}
            put(2, 2) -> cache = {1=1, 2=2}
            get(1) -> returns 1, cache = {2=2, 1=1}
            put(3, 3) -> cache = {1=1, 3=3} (2 is removed because it is the least recently used)
            get(2) -> returns -1 (not found)
            put(4, 4) -> cache = {3=3, 4=4} (1 is removed because it is the least recently used)
            get(1) -> returns -1 (not found)

        - We have to implement these following operations:-
            i. Constructor: To initialize the cache with a given capacity.
            ii. get(key): To get the value of the key if it exists in the cache,
                otherwise return -1.
            iii. put(key, value): To insert the value if the key is not already present.
                If the cache reached its capacity, it should invalidate the least recently used

        - Using doubly linked list to keep track of the order of the elements,
            with the most recently used element at the right end and
                the least recently used element at the left end.
        - Using a hash map to keep track of the key and the counter value for that key,
            with the key being the key of the element and
                the value being the pointer to the node in the doubly linked list.

    Explanation:-
        Intialization:-
            * Creating a hashmap and a doubly linked list.
            * Creating a dummy head and a dummy tail for the doubly linked list.
            * Creating a capacity variable to keep track of the capacity of the cache.

        Constructor:-
            * Initializing the capacity variable with the given capacity.
            * Initializing the dummy head and dummy tail nodes.
            * Linking the dummy head and dummy tail nodes.

        Remove function (helper function):-
            * Takes the current node as input and removes it from the doubly linked list.
            * To remove the node, we perform the following steps:-
                i. Get the previous node of the current node.
                ii. Get the next node of the current node.
                iii. Set the next pointer of the previous node to the next node.
                iv. Set the previous pointer of the next node to the previous node.
            Ex:-
                * If we have a doubly linked list like this:-
                    left <-> 1 <-> 2 <-> 3 <-> right
                * And we want to remove the node with value 2,
                    then we perform the following steps:-
                        i. Get the previous node of the current node (1).
                        ii. Get the next node of the current node (3).
                        iii. Set the next pointer of the previous node (1) to the next node (3).
                        iv. Set the previous pointer of the next node (3)
                            to the previous node (1).
                * After performing these steps, the doubly linked list will look like this:-
                    left <-> 1 <-> 3 <-> right

        Insert function (helper function):-
            * Takes the current node as input and inserts it at the right
                end of the doubly linked list.
            * To insert the node, we perform the following steps:-
                i. Get the previous node of the dummy tail node.
                ii. Set the next pointer of the previous node to the current node.
                iii. Set the previous pointer of the current node to the previous node.
                iv. Set the next pointer of the current node to the dummy tail node.
                v. Set the previous pointer of the dummy tail node to the current node.
            Ex:-
                * If we have a doubly linked list like this:-
                    left <-> 1 <-> 3 <-> right
                * And we want to insert the node with value 2,
                    then we perform the following steps:-
                        i. Get the previous node of the dummy tail node (3).
                        ii. Set the next pointer of the previous node (3)
                            to the current node (2).
                        iii. Set the previous pointer of the current node (2)
                            to the previous node (3).
                        iv. Set the next pointer of the current node (2)
                            to the dummy tail node (right).
                        v. Set the previous pointer of the dummy tail node (right)
                            to the current node (2).
                * After performing these steps, the doubly linked list will look like this:-
                    left <-> 1 <-> 3 <-> 2 <-> right

        Get function:-
            * Takes the key as input and returns the value of the key if it exists in the cache,
                otherwise returns -1.
            * To get the value of the key, we perform the following steps:-
                i. Check if the key exists in the cache or not.
                    - If it exists, then we perform the following steps:-
                        a. Remove the node from the doubly linked list.
                        b. Insert the node at the right end of the doubly linked list.
                        c. Return the value of the key.
                        (
                            The reason we are removing and inserting is,
                                because now the node is the most recently used node,
                            so we need to move it to the right end of the doubly linked list.
                        )
                    - If it doesn't exists, then we return -1.

        Put function:-
            * Takes the key and value as input and inserts the value if the key is not already present.
                If the cache reached its capacity, it should invalidate the least recently used item.
            * To insert the value, we perform the following steps:-
                i. Check if the key exists in the cache or not.
                    - If it exists, then we perform the following steps:-
                        a. Remove the node from the doubly linked list.
                        b. Delete the node from the cache.
                    - If it doesn't exists, then we perform the following steps:-
                        a. Create a new node with the given key and value.
                        b. Insert the node at the right end of the doubly linked list.
                        c. Add the node to the cache.
                ii. Check if the size of the cache exceeds its capacity or not.
                    - If it exceeds, then we perform the following steps:-
                        a. Get the least recently used node (the node next to dummy head).
                        b. Remove the node from the doubly linked list.
                        c. Delete the node from the cache.
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
