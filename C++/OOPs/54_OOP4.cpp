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
    friend void setx(ABC &, int);
};

void setx(ABC &a,int b){
    a.x = b;
}



int main() { 

    ABC a1;
    a1.set(3);
    cout<<a1.get()<<endl;
    setx(a1,2000);
    cout<<a1.get();


    return 0;
}
