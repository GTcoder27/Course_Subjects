#include <bits/stdc++.h>
using namespace std;
// You have given sorted linked list delete duplicates and return in sorted order

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

void deleteRepeated(Node* &head){
    Node* prev = head;
    Node* temp = head->next;
    while(temp != NULL){
        if(temp->value == prev->value){
            prev->next = temp->next;
            Node* to_delete = temp;
            temp = prev->next;
            free(to_delete);
        }
        else{
            prev = temp;
            temp = temp->next;
        }
    }   
}

int main() {
    
    Node* head = NULL;
    insertAtEnd(head,1);
    display(head);
    insertAtEnd(head,2);
    display(head);
    insertAtEnd(head,4);
    display(head);
    insertAtEnd(head,4);
    display(head);
    insertAtEnd(head,5);
    display(head);
    insertAtEnd(head,5);
    display(head);
    insertAtEnd(head,7);
    display(head);
    insertAtEnd(head,7);
    display(head);

    deleteRepeated(head);
    display(head);





    return 0;
}
