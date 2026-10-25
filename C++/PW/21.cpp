#include<bits/stdc++.h>
using namespace std;


void matrix_mul(int a[3][3],int b[3][3]){
    // int c_a = (sizeof(a[0]))/(sizeof(int));
    // int c_b = (sizeof(b[0]))/(sizeof(int));
    // int r_a = (sizeof(a))/(sizeof(a[0]));
    // int r_b = (sizeof(b))/(sizeof(b[0]));
    int c_a = 3 ;
    int c_b = 3 ;
    int r_a = 3 ;
    int r_b = 3 ;
    if(c_a != r_b){
        cout<<"not possible"<<endl;
        return;
    }

    int ans[r_a][c_b];

    for(int i=0;i<r_a;i++){
        for(int k=0;k<c_b;k++){
            int sum = 0;
            for(int j=0;j<c_a;j++){
                sum += a[i][j]*b[j][k];
            }
            ans[i][k] = sum;
        }
    }
    for(int i=0;i<r_a;i++){
        for(int j=0;j<c_b;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }


}


int main()
{
    
    int a[3][3] = {{1,2,3},
                  {4,5,6},
                  {7,3,4} };
    int b[3][3] = {{1,2,0},
                  {2,1,4},
                  {2,1,2} };
    
    matrix_mul(a,b);
    





    return 0;
}
