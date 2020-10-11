#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>

using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
    map<int,Node*> mp; //map the key to the node in the linked list
    int cp;  //capacity
    Node* tail; // double linked list tail pointer
    Node* head; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function

};

// Here starts my code

class LRUCache : public Cache {
    private:
        map<int,Node*> mp; //map the key to the node in the linked list
        int cp;  //capacity
        Node* tail; // double linked list tail pointer
        Node* head; // double linked list head pointer
    public:
        friend ostream &operator<<(ostream& oss, const LRUCache c);
        LRUCache(int capacity): cp{capacity}, tail{nullptr}, head {nullptr}, mp{} {};

        virtual void set(int key, int value){
            if (mp.empty()){
                // create a node and direct head and tail of mp to it
                Node* nd = new Node {key, value};
                mp.insert({key, nd});
                head = mp[key];
                tail = mp[key];
            }
            else if (mp.find(key) == mp.end()){
                if (mp.size() == cp){
                    // redirecting last but one element in the map
                    int new_last_key = tail->prev->key;
                    int last_key = tail->key;
                    tail = mp[new_last_key];
                    tail->next = nullptr;
                    mp.erase(last_key);

                    // add a node and direct head to it and redirect other nodes
                    Node* nd2 = new Node {nullptr, nullptr, key, value};
                    mp.insert({key, nd2});
                    mp[key]->next = head;
                    head->prev = mp[key];
                    head = mp[key];
                }
                else if (mp.size() < cp){
                    Node* nd3 = new Node {nullptr, nullptr, key, value};
                    mp.insert({key, nd3});
                    mp[key]->next = head;
                    head->prev = mp[key];
                    head = mp[key];
                }
            }
            else {
                if (head->key == key){
                    if (head->value != value)
                        head->value = value;
                }
                else if (tail->key == key){
                    int new_last_key = tail->prev->key;
                    tail = mp[new_last_key];
                    tail->next = nullptr;

                    mp[key]->prev = nullptr;
                    mp[key]->next = head;
                    head->prev = mp[key];
                    head = mp[key];
                    if (head->value != value)
                        head->value = value;
                } else {
                    auto it = mp.find(key);
                    it->second->prev->next = it->second->next;
                    it->second->next->prev = it->second->prev;
                    head->prev = it->second;
                    it->second->prev = nullptr;
                    it->second->next = head;
                    head = it->second;
                    if (head->value != value)
                        head->value = value;
                }
            }
        }
        virtual int get(int key) {
            if (mp.find(key) == mp.end())
                return -1;
            else {
                auto it = mp.find(key);
                return it->second->value;
            }
        }
};

ostream &operator<<(ostream& oss, const LRUCache c){
    if (c.mp.size() != 0){
        oss << "\nBegin" << endl;
        oss << c.head->key << ":" << c.head->value << endl;
        Node* temp = c.head->next;
        while (temp != NULL && temp != nullptr){
            oss << temp->key << ":" << temp->value << endl;
            temp = temp->next;
        }
        oss << "End" << endl;
    }
    else {
        oss << "Empty" << endl;
    }
    return oss;
}

// Here ends my code

int main() {
   int n, capacity, i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
       cout << l;
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}

/*
8 2
set 1 2
set 2 3
set 3 4
set 2 4
set 4 5
Segmentation fault (core dumped)
*/