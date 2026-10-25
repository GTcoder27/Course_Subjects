#include <bits/stdc++.h>
using namespace std;


class Rectangle{
public:
    int l;
    int b;

    Rectangle(){ // Default Constructor - No arguments passed
        l = 0;
        b = 0;
    }
    Rectangle(int x,int y){  // Parameterised Constructor - arguments passed
        l = x;
        b = y;
    }
    Rectangle(Rectangle &r2){ // copy Constructor - initialise an object by an existing object
        l = r2.l;
        b = r2.b;
    }
};



int main() {

    Rectangle r1;
    cout<<r1.l<<" "<<r1.b<<endl;

    Rectangle r2(3,4);
    cout<<r2.l<<" "<<r2.b<<endl;

    Rectangle r3 = r2;
    // or Rectangle r3(r2);
    cout<<r3.l<<" "<<r3.b<<endl;
    



    return 0;
}
