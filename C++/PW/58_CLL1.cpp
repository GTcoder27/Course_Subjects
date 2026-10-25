#include <bits/stdc++.h>
using namespace std;
// Circular Linked List

class Node{
public: 
    int value;
    Node* next;
    Node(int data){
        value = data;
        next = NULL;
    }
};

class CircularLinkedList{
public:
    Node* head;

    CircularLinkedList(){
        head = NULL;
    }
    void insertAtTail(int value){
        Node* new_node = new Node(value);
        if(head == NULL){
            head = new_node;
            new_node->next = head;
            return;
        }
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = head;
    }

    void display(){
        Node* temp = head;
        do{
            cout << temp->value << "->";
            temp = temp->next;
        }while(temp != head);
        cout<<"NULL"<<endl;
    }
};

bool check_same(Node* &head1,Node* &head2){
    if(head1 == NULL || head2 == NULL){
        return true;
    }
    Node* temp1 = head1;
    Node* temp2 = head2;
    if(temp1->value != temp2->value){
        return false;
    }
    else{
        return check_same(temp1->next,temp2->next);
    }
}



int main() {
    
    CircularLinkedList li1;
    li1.insertAtTail(1);
    li1.insertAtTail(2);
    li1.insertAtTail(3);
    li1.insertAtTail(4);
    li1.insertAtTail(5);
    li1.insertAtTail(6);
    li1.insertAtTail(7);
    li1.display();




    return 0;
}
