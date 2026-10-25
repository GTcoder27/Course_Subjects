#include <bits/stdc++.h>
#include<list>
using namespace std;
// STL implimentation of Linked List
// li.begin() -> iterator for first element 
// li.end() -> iterator for position after last element
// li.rbegin() -> iterator for first element in reverse iteration
// li.rend() -> iterator for position after last element in reverse iteration
// advance(it,n) -> advances the iterator by two places
// li.insert(it,value) -> insert value before the position of iterator
// li.insert(it,count,value) -> insert value count number of times before iterator
// li.erase(it) -> delete element of iterator
// li.erase(it_start,it_end) -> delete element from start to end-1 iterator
// push_front(val) -> insert value in the front of the list 
// pop_front() -> removes value from front of the list
// push_back(val) -> insert value in the back of the list
// pop_back() -> removes value from the back of the list


int main() {
    
    list<int> l1 = {1,2,3,4,5};
    // auto itr = l1.begin();
    // cout<<*itr<<endl;
    // advance(itr,2);
    // cout<<*itr<<endl;
    l1.push_back(10);

    for(auto it = l1.begin();it != l1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    for(auto it = l1.rbegin();it != l1.rend();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    auto it = l1.begin();
    l1.insert(it,50);
    l1.insert(it,60);
    it++;
    l1.insert(it,3,12);
    l1.erase(it);

    for(auto it = l1.begin();it != l1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    auto it1 = l1.begin();
    advance(it1,3);
    auto it2 = l1.begin();
    advance(it2,6);
    l1.erase(it1,it2);
    
    for(auto it = l1.begin();it != l1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl; 

    auto it3 = l1.begin();
    advance(it3,2);
    l1.erase(it3);

    for(auto it = l1.begin();it != l1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;


    return 0;
}
