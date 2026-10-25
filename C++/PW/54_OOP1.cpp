#include <bits/stdc++.h>
using namespace std;


class Fruits{
public:
    string name;
    string color;
};



int main() {
    
    Fruits apple;
    apple.name = "Apple";
    apple.color = "Red";
    cout<<apple.name<<" - "<<apple.color<<endl;

    Fruits *mango = new Fruits();
    mango->name = "Mango";
    mango->color = "Yellow";
    cout<<mango->name<<" - "<<mango->color<<endl;



    return 0;
}
