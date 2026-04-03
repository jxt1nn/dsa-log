/*  
    LRUCache(int capacity) Initialize the LRU cache with positive size capacity

    means we can store only K [key,value] pairs...

    get(int key) Return the value of the key if the key exists, otherwise return -1

    void put(int key, int value) Update the value of the key if the key exists.
    Otherwise, add the key-value pair to the cache. 

    If the number of keys exceeds the capacity from this operation, 
    evict the least recently used key

    functions get and put must each run in O(1) average time complexity.


    by reading last line.....we get the hint of unorderd map 

    bcoz their is no other data structure that give us mapping result in O(1)

    map can do thing like:
        finding
        updating existing value
    
    but map cannot keep the tracak off  least recently used [key,value] pair

    Understand “Least Recently Used (LRU)”

    Think like this:

    You have limited space (capacity)
    Every time you use something → it becomes recently used
    The one you didn’t use for the longest time → least recently used

    Example:

    Capacity = 2

    put(1,10) → cache = {1}
    put(2,20) → cache = {1,2}

    get(1) → access 1 → now 1 is most recent
    cache order = {2 (old), 1 (new)}

    put(3,30) → capacity full → remove 2 (least used)
    cache = {1,3}

    get(key)
        If key exists → return value
        If not → return -1
        ALSO → mark it as recently used

    put(key, value)
        If key exists → update value + mark recent
        If new key:
        If space available → insert
        If full → remove least recently used, then insert

    Structure	        problem
    Array / Vector	    O(n) removal
    Map only	        can't track order
    Queue	            can't update middle

    1. Fast access by key → unordered_map
    👉 gives O(1) lookup

    2. Track usage order → doubly linked list
    👉 helps:
        move node to front (recent)
        remove last node (least recent)

    unordered_map<int, node*>  // key → node
    Doubly Linked List:
    [Most Recent ...... Least Recent]

    unordered_map<int, Node*> mp;
    we storing node address bcoz  this help us to locate value in  doubly linklist

    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;
    };


    👉 Create two dummy nodes:

    head → most recent side
    tail → least recent side

    Structure:

    head <-> ...nodes... <-> tail

    👉 Initially:
    head <-> tail

    remove(node){
        p = node-> prev;
        n = node-> next;

        p-> next = n;
        n-> prev = p;
    }   

    Insert node at front (after head) :

    insertnode(node){
        currhead = head->next;
        node-> next = currhead;
        node->prev = head;

        currhead-> prev = node;
        head->next = node;
    }
        
*/
class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;
        
        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    int cap;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    // Constructor
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    // Remove a node
    void remove(Node* node) {
        Node* p = node->prev;
        Node* n = node->next;

        p->next = n;
        n->prev = p;
    }

    // Insert right after head (most recent)
    void insert(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        Node* node = mp[key];
        
        remove(node);     // remove from current position
        insert(node);     // move to front

        return node->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // key exists → remove old node
            Node* node = mp[key];
            remove(node);
            mp.erase(key);
        }

        // if full → remove LRU
        if (mp.size() == cap) {
            Node* lru = tail->prev;
            remove(lru);
            mp.erase(lru->key);
        }

        // insert new node
        Node* node = new Node(key, value);
        insert(node);
        mp[key] = node;
    }
};