class Node{
    public: 
    int key ,value;
    Node* next;
    Node* prev;
    Node(int _key,int _value){
        key =_key;
        value=_value;
        next=NULL;
        prev=NULL;
    }
};

class LRUCache {
    int cap;
    unordered_map<int,Node*>mp;
    Node* head;
    Node* tail;
public:
    LRUCache(int capacity) {
    cap= capacity;
    head =new Node(-1,-1);
    tail = new Node(-1,-1);
    head->next= tail;
    tail->prev=head;
    }
    void deleteNode(Node* node){
        Node* prevnode= node->prev;
        Node* nextnode= node->next;
        prevnode->next= nextnode;
        nextnode->prev= prevnode;
    }
void insertAtFront(Node* node){
    Node* temp =head->next;
    node->next= temp;
    node->prev= head;
    head->next =node;
    temp->prev =node;
}

    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        deleteNode(node);
        insertAtFront(node);
         return node->value;
        
    }
    
    void put(int key, int value) {
if(mp.find(key)!=mp.end()){
    Node* node= mp[key];
    node->value = value;
    deleteNode(node);
    insertAtFront(node);
    return;
}
if(mp.size()== cap){
    Node* lastnode=tail->prev;
    mp.erase(lastnode->key);
    deleteNode(lastnode);
    delete lastnode;
}
    Node* newNode= new Node(key ,value);
    mp[key] = newNode;
    insertAtFront(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */