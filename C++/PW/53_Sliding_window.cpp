#include <bits/stdc++.h>
using namespace std;
// Longest ones

// time complextity -> O(n)
// space complextity -> O(1)


int longestOnes(string str,int k){
    int start = 0;
    int end = 0;
    int zero_count = 0;
    int max_length = 0; 

    for(;end<str.length();end++){
        if(str[end] == '0'){
            zero_count++;
        }
        while(zero_count>k){
            if(str[start] == '0') zero_count--;
            start++; // contracting our window
        }
        max_length = max(max_length,end-start+1);
    }
    return max_length;
}

int main() {
    
    string s ;
    cin>>s;
    int k;
    cin>>k;

    cout<<longestOnes(s,k);
    return 0;
}



// input
// 0001101011
// 2
