#include <bits/stdc++.h>
using namespace std;


class ABC{
    int x;

public:
    void set(int n){
        x = n;
    }
    int get(){
        return x;
    }
};



int main() { 

    ABC a1;
    a1.set(3);
    cout<<a1.get();
    



    return 0;
}
