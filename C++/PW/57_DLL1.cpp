#include <bits/stdc++.h>
using namespace std;
// Doubly Linked List

class Node{
public: 
    int value;
    Node* prev;
    Node* next;
    Node(int data){
        value = data;
        prev = NULL;
        next = NULL;
    }
};


class DoublyLinkedList{
public:
    Node* head;
    Node* tail;

    DoublyLinkedList(){
        head = NULL;
        tail = NULL;
    }
    void insertAtTail(int value){
        Node* new_node = new Node(value);
        if(head == NULL && tail == NULL){
            head = new_node;
            tail = new_node;
            return;
        }
        Node* temp = head;
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }

    void display(){ // from left
        Node* temp = head;
        while(temp != NULL){
            cout << temp->value << "<->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
    void displayFromRight(){
        Node* temp = tail;
        while(temp != NULL){
            cout << temp->value << "<->";
            temp = temp->prev;
        }
        cout<<"NULL"<<endl;
    }
};



int main() {
    

    DoublyLinkedList li1;
    li1.insertAtTail(1);
    li1.insertAtTail(2);
    li1.insertAtTail(3);
    li1.insertAtTail(4);
    li1.insertAtTail(5);
    li1.insertAtTail(6);
    li1.insertAtTail(7);
    li1.display();
    li1.displayFromRight();

    


    return 0;
}
