#include<bits/stdc++.h>
using namespace std;

int power(int a, int b)
{
    if(b == 0)
    {
        return 1;
    }
    int ans = 1;
    while(b--)
    {
        ans *= a;
    }
    return ans; 
}

int main()
{
    string myinput;
    cin>>myinput;
    int m = myinput.length();
    cout<<"m(data bits) = "<<m<<endl;
    int r;
    for(int i=0;i<100;i++)
    {
        if(power(2,i) >= (m+i+1))
        {
            r = i;
            break;
        }
    }
    cout<<"r(redundant bits) = "<<r<<endl;
    int total_bits = r + m;
    cout<<"Total bits  = "<<total_bits<<endl;
    vector<string> v1;
    int temp = 0,temp2 = myinput.length()-1;
    for(int i=0;i<total_bits;i++)
    {
        if(power(2,temp) == i) {
            v1.push_back("r" + to_string(i));
        }
        else {
            v1.push_back(to_string(myinput[temp2--]));
        }
    }
    for(int i=0;i<total_bits;i++)
    {
        cout<<v1[i]<<" ";
    }


    

    return 0;
}
