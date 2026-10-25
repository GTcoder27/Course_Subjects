#include <bits/stdc++.h>
using namespace std;
// Diamond Problem

class parent{
public:
    parent(){
        cout<<"parent class"<<endl;
    }
};
class child1 : public parent{
public:
    child1(){
        cout<<"child1 class"<<endl;
    }
};
class child2 : public parent{
public:
    child2(){
        cout<<"child2 class"<<endl;
    }
};
class grandchild : public child1,public child2{
public:
    grandchild(){
        cout<<"grandchild class"<<endl;
    }
};


int main() { 

    grandchild g;

    return 0;
}


