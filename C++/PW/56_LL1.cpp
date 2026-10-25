#include <bits/stdc++.h>
using namespace std;
// Check that two linked lists are same or not

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
    
    LinkedList li1;
    li1.insertAtTail(1);
    li1.insertAtTail(2);
    li1.insertAtTail(3);
    li1.insertAtTail(4);
    li1.insertAtTail(5);
    li1.insertAtTail(6);
    li1.insertAtTail(7);
    li1.display();

    LinkedList li2;
    li2.insertAtTail(1);
    li2.insertAtTail(2);
    li2.insertAtTail(3);
    li2.insertAtTail(4);
    li2.insertAtTail(5);
    li2.insertAtTail(6);
    li2.insertAtTail(7);
    li2.display();

    cout<<check_same(li1.head,li2.head);


    return 0;
}
