#include <bits/stdc++.h>
using namespace std;
// Reverse the nodes of the list k at a time, and return the modified list

class Node{
public: 
    int value;
    Node* next;
    Node(int data){
        value = data;
        next = NULL;
    }
};

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

Node* reverseLL_Knodes(Node* &head,int k){
    Node* prevptr = NULL;
    Node* currptr = head;
    int counter = 0; // for counting first k nodes
    while(currptr != NULL && counter<k){ // Reversing first k nodes
        Node* nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        counter++;
    }

    // currptr will give us (k+1)th node
    if(currptr != NULL){
        Node* new_head = reverseLL_Knodes(currptr,k);
        head->next = new_head;
    }
    return prevptr; // preptr will give the new_head of connected linked lists
}




int main() {
    
    LinkedList li;
    li.insertAtTail(1);
    li.insertAtTail(2);
    li.insertAtTail(3);
    li.insertAtTail(4);
    li.insertAtTail(5);
    li.insertAtTail(6);
    li.insertAtTail(7);
    li.display();

    li.head = reverseLL_Knodes(li.head,2);
    li.display();


    return 0;
}
