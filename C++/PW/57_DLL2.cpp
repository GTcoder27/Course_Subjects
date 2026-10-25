#include <bits/stdc++.h>
using namespace std;
// insert at kth position

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
            cout << temp->value<<" ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
    void displayFromRight(){
        Node* temp = tail;
        while(temp != NULL){
            cout << temp->value<<" ";
            temp = temp->prev;
        }
        cout<<"NULL"<<endl;
    }
};


void insertAtK(Node* &head,int k,int value){
    int count = 1;
    Node* temp = head;
    while(count < (k-1)){
        temp = temp->next;
        count++;
    }

    Node* new_node = new Node(value);
    new_node->next = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next->prev = new_node;
}


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

    insertAtK(li1.head,4,10);
    li1.display();


    return 0;
}
