#include<iostream>
using namespace std;

int main(){
    int a[10],b[10],c1,c2,c3;
    cout<<"\nEnter the 4 bits : \n";

// Data bits
    cin>>a[3];
    cin>>a[5];
    cin>>a[6];
    cin>>a[7];

// Parity Bits
a[1]=a[3]^a[5]^a[7];
a[2]=a[3]^a[6]^a[7];
a[4]=a[5]^a[6]^a[7];

for(int i=1;i<8;i++){
    cout<<"\t"<<a[i];
    }

cout<<"\nEnter the 7 Bits :\n";
for(int i=1;i<8;i++){
    cin>>b[i];

}

//calculate parity bits

c1=b[1]^b[3]^b[5]^b[7];
c2=b[2]^b[3]^b[6]^b[7];
c3=b[4]^b[3]^b[5]^b[7];

//convert parity bits in decimal value

int p = c1*1+c2*c3*4;

if(p==0){
    cout<<"\nThere is no Error in the Data ";

}
else{
    cout<<"\nThere is error in the position "<<p;

    //Inverting the position of error word
    if(b[p]==0){
        b[p]=1;

    }
    else{
        b[p]=0;
        
    }
}


return 0;
}