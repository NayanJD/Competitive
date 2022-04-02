#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct Node {
    int value;
    int key;
    Node *next;
    Node *prev;

    Node(int key, int value, Node *next, Node *prev) : key(key), value(value), next(next), prev(prev) {}
};

class LRUCache {
    Node *head;
    Node *last;
    unordered_map<int, Node*> map;
    int totalCapacity;
    int currentCapacity;
public:
    LRUCache(int capacity) {
        head = nullptr;
        last = nullptr;
        totalCapacity = capacity;
        currentCapacity = 0;
    }
    
    int get(int key) {
        if(map.find(key) != map.end()){
            // printf("For key %d\n", key);

            Node *node = map[key];

            if(node->prev != nullptr){
                // printf("In here ... \n");
                node->prev->next = node->next;
            }

            if(node->next != nullptr && node != head){
                // printf("In here too \n");
                node->next->prev = node->prev;
            }

            if(last == node && last != head){
                last->prev->next = nullptr;
                last = last->prev;
            }

            if(head != node){
                
                node->next = head;
                head->prev = node;

                head = node;
            }
            
            node->prev = nullptr;

            // printf("head: %d\n", last->prev);
            return node->value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()){
            Node *node = map[key];
            node->value = value;

            if(node->prev != nullptr){
                node->prev->next = node->next;
            }

            if(node->next != nullptr && node != head){
                node->next->prev = node->prev;
            }

            if(last == node && last != head){
                last->prev->next = nullptr;
                last = last->prev;
            }

            if(head != node){
                node->next = head;
                head->prev = node;

                head = node;
            }

            node->prev = nullptr;
            
        } else {
            Node *newNode = new Node(key, value, head, nullptr);
            map[key] = newNode;

            if(head != nullptr){
                head->prev = newNode;
            }

            head = newNode;

            if(currentCapacity == 0){
                last = head;
            }

            if(currentCapacity == totalCapacity){
                Node *temp = last;
                last->prev->next = nullptr;
                last = last->prev;

                map.erase(temp->key);
                delete temp;
            } else {
                currentCapacity++;
            }

            
        }

        
    }

    void printNodes(){
        Node *node = head;

        printf("Forward: ");
        while(node != nullptr){
            printf("%d, ", node->key);
            node = node->next;
        }

        printf("\n");

        printf("Backward: ");

        node = last;
        while(node != nullptr){
            printf("%d, ", node->key);
            node = node->prev;
        }

        printf("\n");
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
    LRUCache* obj = new LRUCache(2);

    // obj->put(1, 1);
    // // obj->printNodes();
    // obj->put(2,2);
    // // obj->printNodes();
    // printf("%d\n", obj->get(1));
    // obj->put(3,3);
    // // obj->printNodes();
    // printf("%d\n", obj->get(2));
    // obj->put(4, 4);

    // printf("%d\n", obj->get(1));
    // printf("%d\n", obj->get(3));
    // printf("%d\n", obj->get(4));

    obj->get(2);
    obj->put(2,6);
    obj->get(1);
    obj->put(1,5);
    // obj->printNodes();
    obj->put(1,2);
    obj->get(1);
    obj->get(2);
    obj->printNodes();


    return 0;
}