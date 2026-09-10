/*
    https://leetcode.com/problems/lfu-cache/
*/
/*
    Solution Approach:- Using Custom Doubly Linked List and HashMap

    Time Complexity:- O(1)
    Space Complexity:- O(N)
    N = number of elements in the cache

    Intuition:-
        - We have to implement a data structure that is used to insert values with their keys.
        - Also have been given a certain capacity of the cache, which we have to maintain.
        - There are the following operations which we need to perform:-
            i. get(key) - Get the value of the key if the key exists in the cache, otherwise return -1.
            ii. put(key, value) - Update the value of the key if present,
                                    or insert the key if not already present.
                When the cache reaches its capacity, it should invalidate
                    the least frequently used item before inserting a new item.
                If there is a tie (i.e., two or more keys with the same frequency),
                    the least recently used key would be evicted.

        - Example:-
            Input
                ["LFUCache","put","put","get","put","get","get","put","get","get","get"]
                [[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]
            Output
                [null,null,null,1,null,-1,3,null,-1,3,4]
            Explanation
                LFUCache lfu = new LFUCache(2);
                lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
                lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
                lfu.get(1);      // return 1
                                 // cache=[1,2], cnt(2)=1, cnt(1)=2
                lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest,
                                 // invalidate 2.
                                 // cache=[3,1], cnt(3)=1, cnt(1)=2
                lfu.get(2);      // return -1 (not found)
                lfu.get(3);      // return 3
                                 // cache=[3,1], cnt(3)=2, cnt(1)=2
                lfu.put(4, 4);   // Both 1 and 3 have the same cnt,
                                 // but 1 is LRU, invalidate 1.
                                 // cache=[4,3], cnt(4)=1, cnt(3)=2
                lfu.get(1);      // return -1 (not found)
                lfu.get(3);      // return 3
                                 // cache=[3,4], cnt(4)=1, cnt(3)=3
                lfu.get(4);      // return 4
                                 // cache=[4,3], cnt(4)=2, cnt(3)=3

    - Using a custom doubly linked list, so we can maintain the order of the elements in the cache.
    - Using hashmaps to store the values and their counts, so we can access them in O(1) time.
*/
/*
    Code:- Node Implementation

    Explanation:-
        * This is the node implementation which has the following attributes:-
            - val: The value of the node.
            - prev: Pointer to the previous node.
            - next: Pointer to the next node.
        * This node is used to store the values in the doubly linked list.
*/
struct Node {
    int val;
    Node* prev;
    Node* next;

    Node(int v = 0, Node* p = nullptr, Node* n = nullptr)
        : val(v), prev(p), next(n) {}
};

/*
    Code:- Custom Doubly Linked List Implementation

    Explanation:-
        * This is the custom doubly linked list implementation.
        * These are the following parameters of the linked list:-
            - left: Pointer to point at the start of the linked list.
            - right: Pointer to point at the end of the linked list.
            - map: Hashmap to store the values and their corresponding nodes.
        * This linked list is used to maintain the order of the elements in the cache.

    Function Implementation:-
        i. length(): Returns the length of the linked list i.e. the number of elements in the hashmap.
        ii. pushRight(int val):
            - First it takes the values and creates a new node with the value.
            - Then adding the value and the node to the hashmap.
            - Then adding the node to the right of the linked list.
        iii. pop(int val):
            - First it checks if the value is present in the hashmap.
            - If present, it gets the node from the hashmap and removes it from the linked list
            - Storing the previous and the next node of the current node and updating their pointers.
            - Then removing the value from the hashmap and deleting the node.
        iv. popLeft():
            - First it gets the value of the left node.
            - Then calling the pop function to remove the left node from the linked list.
            - Finally returning the value of the left node.
*/
class LinkedList {
public:
    Node* left;
    Node* right;
    unordered_map<int, Node*> map;

    LinkedList() {
        left = new Node(0);
        right = new Node(0, left, nullptr);
        left->next = right;
    }

    int length() {
        return map.size();
    }

    void pushRight(int val) {
        Node* node = new Node(val, right->prev, right);
        map[val] = node;
        right->prev->next = node;
        right->prev = node;
    }

    void pop(int val) {
        if (map.find(val) != map.end()) {
            Node* node = map[val];
            Node* nextNode = node->next;
            Node* prevNode = node->prev;

            nextNode->prev = prevNode;
            prevNode->next = nextNode;

            map.erase(val);
            delete node;
        }
    }

    int popLeft() {
        int res = left->next->val;
        pop(res);
        return res;
    }

    void update(int val) {
        pop(val);
        pushRight(val);
    }
};

class LFUCache {
    private:
        int cap;
        int lfuCnt;
        unordered_map<int, int> valMap;
        unordered_map<int, int> countMap;
        unordered_map<int, LinkedList*> listMap;

        void counter(int key) {
            int count = countMap[key];
            countMap[key]++;

            listMap[count]->pop(key);

            if (listMap.find(count + 1) == listMap.end())
                listMap[count + 1] = new LinkedList();

            listMap[count + 1]->pushRight(key);

            if (count == lfuCnt && listMap[count]->length() == 0)
                lfuCnt++;
        }

    public:
        LFUCache(int capacity) {
            cap = capacity;
            lfuCnt = 0;
        }

        int get(int key) {
            if (valMap.find(key) == valMap.end())
                return -1;

            counter(key);
            return valMap[key];
        }

        void put(int key, int value) {
            if (cap == 0) return;

            if (valMap.find(key) != valMap.end()) {
                valMap[key] = value;
                counter(key);
                return;
            }

            if (valMap.size() == cap) {
                int evictedKey = listMap[lfuCnt]->popLeft();
                valMap.erase(evictedKey);
                countMap.erase(evictedKey);
            }

            valMap[key] = value;
            countMap[key] = 1;
            lfuCnt = 1;

            if (listMap.find(1) == listMap.end())
                listMap[1] = new LinkedList();

            listMap[1]->pushRight(key);
        }
};
