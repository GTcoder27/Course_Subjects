#include <bits/stdc++.h>
using namespace std;
// swap every adjacent two nodes

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

Node* swap2nodes(Node* &head){
    
    //base case
    if(head == NULL || head->next == NULL){
        return head;
    }

    //recursive case
    Node* secondNode = head->next;
    head->next = swap2nodes(secondNode->next);
    secondNode->next = head; //reversing the link between first and second node
    return secondNode;
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

    li1.head = swap2nodes(li1.head);
    li1.display();


    return 0;
}
