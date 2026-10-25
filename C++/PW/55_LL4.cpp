#include <bits/stdc++.h>
using namespace std;
// Print the singly linked list in reverse order

class Node{
public: 
    int value;
    Node* next;
    Node(int data){
        value = data;
        next = NULL;
    }
};
void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->value<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

void insertAtEnd(Node* &head,int value){
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

void reverseOrder_printing(Node* &temp){
    if(temp == NULL) return;
    reverseOrder_printing(temp->next);
    cout<<temp->value<<" -> ";
}


int main() {
    
    Node* head = NULL;
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,5);
    insertAtEnd(head,6);
    insertAtEnd(head,7);
    insertAtEnd(head,8);
    display(head);

    reverseOrder_printing(head);






    return 0;
}
