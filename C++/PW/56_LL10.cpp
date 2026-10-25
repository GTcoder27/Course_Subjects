#include <bits/stdc++.h>
using namespace std;
// rotate the linked list

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

Node* rotateByK(Node* &head,int k){
    
    //1. find the length of linked list
    int n = 0;
    //2.find tail node
    Node* tail = head; 

    while(tail->next){
        n++;
        tail = tail->next;
    }
    n++; //for including last node

    k = k%n;
    if(k==0){
        return head;
    } 
    tail->next = head;
    //3.traverse n-k nodes
    Node* temp = head;
    for(int i=1;i<n-k;i++){
        temp = temp->next;
    }
    // temp is now pointing to (n-k)th node

    Node* newhead = temp->next;
    temp->next = NULL;
    return newhead;
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

    li1.head  = rotateByK(li1.head,3);
    li1.display();


    return 0;
}
