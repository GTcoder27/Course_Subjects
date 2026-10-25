#include <bits/stdc++.h>
using namespace std;
// Template Classes -> Allows us to pass different data type as parameters.


template <typename T>
class Node{
public: 
    T value;
    Node* next;
    Node(T data){
        value = data;
        next = NULL;    
    }
};


int main() {
    
    Node<int>* node1 = new Node<int> (3);
    cout<<node1->value<<endl;

    Node<char>* node2 = new Node<char>('a');
    cout<<node2->value<<endl;




    return 0;
}
