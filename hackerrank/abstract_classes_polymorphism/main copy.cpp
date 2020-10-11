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
        LRUCache(int capacity): cp{capacity}, tail{nullptr}, head {nullptr} {};

        virtual void set(int key, int value){
            if (mp.empty()){
                // create a node and direct head and tail of mp to it
                Node* nd = new Node {key, value};
                head = nd;
                tail = nd;
                mp.insert({key, nd});
            }
            else if (mp.find(key) == mp.end()){
                if (mp.size() == cp){
                    // redirecting last but one element in the map
                    tail->prev->next = nullptr;
                    Node* temp = tail->prev;
                    Node* last = tail;
                    // deleting last element
                    int tempy = tail->key;
                    mp.erase(tempy);
                    tail = temp;
                    delete temp;
                    delete last;

                    // add a node and direct head to it and redirect other nodes
                    Node* nd2 = new Node {nullptr, head, key, value};
                    head->prev = nd2;
                    head = nd2;
                    mp.insert({key, nd2});
                }
                else if (mp.size() < cp){
                    Node* nd3 = new Node {nullptr, head, key, value};
                    head->prev = nd3;
                    head = nd3;
                    mp.insert({key, nd3});
                }
            }
            else {
                if (head->key == key){
                    ;
                }
                else if (tail->key == key){
                    tail->prev->next = nullptr;
                    Node* tempy_back = tail->prev;
                    head->prev = tail;
                    head = tail;
                    tail = tempy_back;
                } else {
                    auto it = mp.find(key);
                    it->second->prev->next = it->second->next;
                    it->second->next->prev = it->second->prev;
                    head->prev = it->second;
                    it->second->prev = nullptr;
                    it->second->next = head;
                    head = it->second;
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

// Here ends my code

int main() {
   int n, capacity, i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
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
