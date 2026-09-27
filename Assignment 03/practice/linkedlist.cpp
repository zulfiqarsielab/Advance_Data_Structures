#include <iostream>
using namespace std;


class Node {
    public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};
class List {
    
    Node* head;
    Node* tail;

    public:
    List(){
        head = tail = NULL;
    }
        void push_front(int val) {
            Node* newNode  = new Node(val);
            if (head == NULL) {
                head = tail = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
        
        }

        void push_back(int val) {
            Node* newNode  = new Node(val);
            if (head == NULL) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        void pop_front() {
            if (head ==NULL) {
                cout << "Link List is empty" << endl;
            } else {
                Node* temp = head;
                head = head->next;
                temp->next = NULL;
                delete temp;
            }
        }
        void pop_back() {
            if (head == NULL) {
                cout << "Link List is empty" << endl;
                return;

            } 
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            temp->next = NULL;
            delete tail;
            tail = temp;
        }

        void printLL() {
            Node* temp = head;

            while (temp != NULL) {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    
    
};



int main() {
    List ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.push_back(40);
    ll.pop_front();

    ll.printLL();
    return 0;
}