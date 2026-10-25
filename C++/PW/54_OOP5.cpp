#include <bits/stdc++.h>
using namespace std;


class parent{

public:
    int a = 1;
protected:
    int b = 6;
private:
    int c = 3;
};
class parent2{

public:
    int a = 1;
protected:
    int b = 6;
private:
    int c = 3;
};

class child: public parent{
    // x will remain public
    // y will remain protected
    // z will not be accessible
}
class child: private parent{
    // x will remain private
    // y will remain private
    // z will not be inaccessible
}
class child: protected parent{
    // x will remain protected
    // y will remain protected
    // z will not be inaccessible
}
class child: public parent,public parent2{

}

int main() { 

    parent a1;
    cout<<a1.a<<endl;
    cout<<a1.b<<endl;
    // cout<<a1.a<<endl;
    



    return 0;
}
