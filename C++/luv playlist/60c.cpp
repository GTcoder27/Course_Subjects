#include<bits/stdc++.h>
using namespace std;

void printBinary(int num){
    for(int i=10;i>=0;i--){
        cout<<((num >> i) & 1);
    }
    cout<<endl;
}

int main()
{
    // uppercase to lowercase & lowercase to uppercase

    // for(char c='A';c<='Z';c++){
    //     cout<<c<<" -> ";
    //     printBinary(int(c));
    //     cout<<endl;
    // }
    // for(char c='a';c<='z';c++){
    //     cout<<c<<" -> ";
    //     printBinary(int(c));
    //     cout<<endl;
    // }

    // char capital = 'A';
    // char small = capital | (1<<5);
    // cout<<small<<endl;

    // printBinary(int('_'));

    char B = 'B';
    // Uppercse to lowercase
    cout<<char(B | ' ')<<endl;

    // lowercase to uppercase 
    char d = 'd';
    cout<<char(d & '_')<<endl;



    return 0;
}
