#include <bits/stdc++.h>
using namespace std;
// Odd even linked List
// group all nodes with odd indices together followed by the nodes with even indices and return the reordered nodes

class Node{
public: 
    int value;
    Node* next;
    Node(int data){
        value = data;
        next = NULL;
    }
};


class LinkedList{
public:
    Node* head;

    LinkedList(){
        head = NULL;
    }
    void insertAtTail(int value){
        Node* new_node = new Node(value);
        if(head == NULL){
            head = new_node;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->value << "->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

Node* oddEvenLL(Node* &head){

    Node* odd_h = head;
    Node* even_h = head->next;
    Node* even_head = head->next;

    while(even_h && even_h->next){
        odd_h->next = odd_h->next->next;
        even_h->next = even_h->next->next;
        odd_h = odd_h->next;
        even_h = even_h->next;
    }
    odd_h->next = even_head;
    return head;
}


int main() {
    
    LinkedList li1;
    li1.insertAtTail(1);
    li1.insertAtTail(2);
    li1.insertAtTail(3);
    li1.insertAtTail(4);
    li1.insertAtTail(5);
    li1.insertAtTail(6);
    li1.insertAtTail(7);
    li1.display();

    li1.head  = oddEvenLL(li1.head);
    li1.display();


    return 0;
}
