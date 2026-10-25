#include <bits/stdc++.h>
using namespace std;
// Merge K number of sorted linked lists

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

Node* mergeK_LL(vector<Node*> &lists){

    if(lists.size() == 0) return NULL;
    while(lists.size()>1){
        Node* mergedHead = mergeLL(lists[0],lists[1]);
        lists.push_back(mergedHead);
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists[0];
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

    LinkedList li3;
    li3.insertAtTail(7);
    li3.insertAtTail(9);
    li3.insertAtTail(10);
    li3.display();

    LinkedList li4;
    li4.insertAtTail(8);
    li4.insertAtTail(11);
    li4.insertAtTail(12);
    li4.display();

    vector<Node*> lists;
    lists.push_back(li1.head);
    lists.push_back(li2.head);
    lists.push_back(li3.head);
    lists.push_back(li4.head);

    LinkedList merged;
    merged.head = mergeK_LL(lists);
    merged.display();
    
    return 0;
}
