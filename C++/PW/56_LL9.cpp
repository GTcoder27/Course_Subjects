#include <bits/stdc++.h>
using namespace std;
// determine the linked list is pallindrome or not

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

bool isPalindrome(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    // now slow is pointing to the middle element
    // 2. break the linked list in the middle
    Node* curr = slow->next;
    Node* prev = slow;
    slow->next = NULL;

    //3. reverse the second half of the linked list
    while(curr != NULL){
        Node* next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }

    //4. check if the two linked lists are equal
    Node* head1 = head;
    Node* head2 = prev;

    while(head2 != NULL){
        if(head1->value != head2->value){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;

    }
    return true;
}



int main() {
    
    LinkedList li1;
    li1.insertAtTail(1);
    li1.insertAtTail(2);
    li1.insertAtTail(3);
    li1.insertAtTail(5);
    li1.insertAtTail(3);
    li1.insertAtTail(2);
    li1.insertAtTail(1);
    li1.display();

    cout<<isPalindrome(li1.head);


    return 0;
}
