#include <bits/stdc++.h>
using namespace std;
// find that two linked lists are intersecting each other or not

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


int getlength(Node* &head){
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}




Node* getIntersection(Node* &head1,Node* &head2){
    
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    // step 1] find lengths of both linked lists
    int l1 = getlength(head1);
    int l2 = getlength(head2);

    // step 2] find difference k between linked list and move longer linked list ptr by k steps
    int diff = abs(l1 - l2);
    if(l1 > l2){
        while(diff--){
            ptr1 = ptr1->next;
        }
    }
    else{
        while(diff--){
            ptr2 = ptr2->next;
        }
    }

    while(ptr1 != NULL || ptr2 != NULL){
        if(ptr1->value == ptr2->value){
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return NULL;
}



int main() {
    
    LinkedList li1;
    li1.insertAtTail(1);
    li1.insertAtTail(2);
    li1.insertAtTail(3);
    li1.insertAtTail(4);
    li1.insertAtTail(5);
    li1.display();

    LinkedList li2;
    li2.insertAtTail(10);
    li2.insertAtTail(20);
    li2.insertAtTail(3);
    li2.insertAtTail(4);
    li2.insertAtTail(5);
    li2.display();

    Node* ans = getIntersection(li1.head,li2.head);
    cout<<ans->value;


    return 0;
}
