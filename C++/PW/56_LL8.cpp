#include <bits/stdc++.h>
using namespace std;
// delete the cycle from the linked list

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

bool detectCycle(Node* &head){

    if(head == NULL) return false;

    Node* slow = head;
    Node* fast = head;
 
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}

void removeCycle(Node* &head){

    Node* slow = head;
    Node* fast = head;
 
    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(slow!=fast);

    fast = head;
    while(slow->next!=fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}



int main() {
    
    LinkedList li1;
    li1.insertAtTail(1);
    li1.insertAtTail(2);
    li1.insertAtTail(3);
    li1.insertAtTail(4);
    li1.insertAtTail(5);
    li1.insertAtTail(6);
    li1.display();

    li1.head->next->next->next->next->next->next = li1.head->next->next;
    cout<<detectCycle(li1.head)<<endl;
    removeCycle(li1.head);
    cout<<detectCycle(li1.head)<<endl;
    li1.display();


    return 0;
}
