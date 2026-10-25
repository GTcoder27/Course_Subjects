#include <bits/stdc++.h>
using namespace std;
// Merge two sorted linked lists 

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



Node* mergeLL(Node* &head1,Node* &head2){
    Node* dummyHeadNode = new Node(-1);

    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* ptr3 = dummyHeadNode;

    while(ptr1 && ptr2){
        if(ptr1->value < ptr2->value){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else{
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }
    if(ptr1){
        ptr3->next = ptr1;
    }else{
        ptr3->next = ptr2;
    }

    return dummyHeadNode->next;
    
}



int main() {
    
    LinkedList li1;
    li1.insertAtTail(1);
    li1.insertAtTail(4);
    li1.insertAtTail(5);
    li1.display();

    LinkedList li2;
    li2.insertAtTail(2);
    li2.insertAtTail(3);
    li2.insertAtTail(6);
    li2.display();

    LinkedList merged;
    merged.head = mergeLL(li1.head,li2.head);
    merged.display();
    
    return 0;
}
