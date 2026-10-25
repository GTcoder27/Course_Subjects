#include <bits/stdc++.h>
using namespace std;
// Reverse singly linked list (Recursively)

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


Node* reverseLLRecursion(Node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    } 
    Node* new_head = reverseLLRecursion(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
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

    li.head = reverseLLRecursion(li.head);
    li.display();


    return 0;
}
