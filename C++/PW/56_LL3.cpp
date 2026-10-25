#include <bits/stdc++.h>
using namespace std;
// remove the kth node from the end of the linked list

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




Node* delete_kth(Node* &head,int k){
    Node* temp = head;
    Node* prev = NULL;
    int counter = 0;
    int lenght = getlength(head);
    while(temp != NULL){
        if(counter == lenght-k){
            if(prev == NULL){
                prev = temp;
                temp = temp->next;
                free(prev);
                return temp;
            }
            else{
                prev->next = temp->next;
                free(temp);
                return head;
            }
        }
        prev = temp;
        temp = temp->next;
        counter++;
    }
    return head;
}



int main() {
    
    LinkedList li1;
    li1.insertAtTail(1);
    li1.insertAtTail(2);
    li1.insertAtTail(3);
    li1.insertAtTail(4);
    li1.insertAtTail(5);
    li1.display();

    li1.head = delete_kth(li1.head,4);
    li1.display();
    
    return 0;
}
