#include <bits/stdc++.h>
using namespace std;
// Diamond Problem

class parent{
public:
    parent(){
        // cout<<"parent class"<<endl;
    }
    void print_bhai(){
        cout<<"bhai parent";
    }
};
class child1 : virtual public parent{
public:
    child1(){
        // cout<<"child1 class"<<endl;
    }
};
class child2 : virtual public parent{
public:
    child2(){
        // cout<<"child2 class"<<endl;
    }
};
class grandchild : public child1,public child2{
    public:
    grandchild(){
        // cout<<"grandchild class"<<endl;
    }
};


int main() { 

    grandchild g;
    g.print_bhai();


    return 0;
}


