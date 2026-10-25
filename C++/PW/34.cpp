#include<bits/stdc++.h>
using namespace std;


bool pal(string str,int i,int n){
    if(i>=n) return true;
    if(str[i] != str[n]){
        return false;
    }    
    return pal(str,i+1,n-1);

}



int main()
{
    string str = "HairnriaH";

    cout<<pal(str,0,str.size()-1);

    

    return 0;
}
