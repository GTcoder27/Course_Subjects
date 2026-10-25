#include <bits/stdc++.h>
using namespace std;

void selection_sort(char fruit[][60], int n){

    for(int i=0;i<n-1;i++){

        // finding min element
        int min_i = i;
        for(int j=i+1;j<n;j++){
            if(strcmp(fruit[min_i],fruit[j]) > 0){
                min_i = j;
            }
        }

        // place the min element at beginning
        if(i!=min_i){
            swap(fruit[i],fruit[min_i]);
        }
    }
    return;
}


int main() {
    
    char fruit[][60] = {"papaya","lime","watermelon","apple","mango","kiwi"};

    int n = sizeof(fruit)/sizeof(fruit[0]);

    selection_sort(fruit,n);
    for(int i=0;i<n;i++){
        cout<<fruit[i]<<" ";
    }

    return 0;
}

// input
// 6
// papaya lime watermelon apple mango kiwi