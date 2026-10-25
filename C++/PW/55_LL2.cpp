#include <bits/stdc++.h>
using namespace std;
// Delete every alternate element from the list starting from second element


class Node{
public: 
    int value;
    Node* next;
    Node(int data){
        value = data;
        next = NULL;
    }
};

void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->value<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

void insertAtHead(Node* &head,int value){
    Node* new_node = new Node(value);
    new_node->next = head;
    head = new_node;
}

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

void insertAtIndex(Node* &head,int value,int index){
    Node* new_node = new Node(value);
    Node* temp = head;
    int temp_index = 0;
    while(temp_index != index-1){
        temp = temp->next;
        temp_index++;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void updateAtIndex(Node* &head,int value,int index){
    Node* temp = head;
    int temp_index = 0;
    while(temp_index != index){
        temp = temp->next;
        temp_index++;
    }
    temp->value = value;
}

void deleteAtStart(Node* &head){
    Node* temp = head; // node to delete
    head = head->next;
    free(temp);
}

void deleteAtEnd(Node* &head){
    Node* temp = head; 
    while((temp->next)->next != NULL){
        temp = temp->next;
    }
    Node* temp2 = temp->next;
    free(temp2);
    temp->next = NULL;
}

void deleteAtIndex(Node* &head,int index){
    Node* temp = head; 
    Node* prev = temp; 
    int temp_index = 0;
    while(temp_index != index){
        prev = temp;
        temp = temp->next;
        temp_index++;
    }
    prev->next = temp->next;
    free(temp);
}

void deleteAlternate(Node* &head){
    Node* temp = head;
    Node* prev = temp;
    int temp_index = 1;
    while(temp != NULL){
        if(temp_index%2 == 0){
            prev->next = temp->next;
            Node* to_delete = temp;
            temp = prev->next;
            free(to_delete);
            temp_index++;
        }
        else{
            prev = temp;
            temp = temp->next;
            temp_index++;
        }
    }
}

int main() {
    
    Node* head = NULL;
    insertAtEnd(head,1);
    display(head);
    insertAtEnd(head,2);
    display(head);
    insertAtEnd(head,3);
    display(head);
    insertAtEnd(head,4);
    display(head);
    insertAtEnd(head,5);
    display(head);
    insertAtEnd(head,6);
    display(head);
    insertAtEnd(head,7);
    display(head);
    insertAtEnd(head,8);
    display(head);

    deleteAlternate(head);
    display(head);





    return 0;
}
