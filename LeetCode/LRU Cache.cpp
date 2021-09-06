class LRUCache {
public:
    class Node{
        public:
            int key;
            int val;
            Node *next;
            Node *prev;
            Node(int _key,int _val){
                key=_key;
                val=_val;
                next=NULL;
                prev=NULL;
            }
    };
    
    int cap;
    unordered_map <int,Node*> mp;
    Node *head=new Node(-1,-1),*tail=new Node(-1,-1);
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addNode(Node *newNode){
        newNode->next=head->next;
        newNode->prev=head;
        head->next=newNode;
        newNode->next->prev=newNode;
    }
    void deleteNode(Node *deleteNode){
        Node *prevDelete=deleteNode->prev;
        Node *nextDelete=deleteNode->next;
        prevDelete->next=nextDelete;
        nextDelete->prev=prevDelete;
    }
    int get(int key) {
        if (mp.find(key)!=mp.end()){
            Node *resnode=mp[key];
            int toReturn=resnode->val;
            mp.erase(key);
            deleteNode(resnode);
            addNode(resnode);
            mp[key]=head->next;
            return toReturn;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (mp.find(key)!=mp.end()){
            Node *resnode=mp[key];
            mp.erase(key);
            deleteNode(resnode);
        }
        if (mp.size()==cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */