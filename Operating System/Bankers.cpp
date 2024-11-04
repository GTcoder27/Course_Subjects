#include <bits/stdc++.h>
using namespace std;
int main() {
    int A=3,B=17,C=16,D=12;
    int given[] ={3,17,16,12};
    string processes[] = {"p0","p1","p2","p3","p4"};
    int allocation[][4]={
        {0,1,1,0},
        {1,2,3,1},
        {1,3,6,5},
        {0,6,3,2},
        {0,0,1,4}
    };
    int max[][4] ={
        {0,2,1,0},
        {1,6,5,2},
        {2,3,6,6},
        {0,6,5,2},
        {0,6,5,6}
    };
    int row = sizeof allocation / sizeof allocation[0];
    int col = sizeof allocation[0] / sizeof(int);
    string pro[row];
    int need[row][col] , available[row+1][col+1], sum_allocation[col];
    for(int i=0;i<col;i++)
    {
        sum_allocation[i] = 0;
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            sum_allocation[j] += allocation[i][j];
        }
    }
    for(int i=0;i<row;i++) // calculating need matrix
    {
        for(int j=0;j<col;j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    int temp_available = 0;
    for(int i=0;i<col;i++) // calculating available matrix
    {
        available[temp_available][i] = given[i]-sum_allocation[i];
    }
    int temp[row];
    for(int i=0;i<row;i++)
    {
        temp[i] = 0;
    }
    int temp_pro = 0;
    int rowtemp = row;
    while(rowtemp--)
    {
        for(int i=0;i<row;i++)
        {
            if(temp[i] == 0)
            {
                int temp2 = 1;

                for(int j=0;j<col;j++)
                {
                    if(available[temp_available][j] >= need[i][j])
                    {
                    }
                    else{
                        temp2 = 0;
                        break;
                    }
                }
                if(temp2 != 0)
                {
                    for(int k=0;k<col;k++)
                    {
                        available[temp_available+1][k] = available[temp_available][k] + allocation[i][k];
                    }
                    temp_available++;
                    temp[i] = 1;
                    pro[temp_pro++] = processes[i];
                }
            }
        }
    }
    cout<<"Final Answer : \nAllocation\tMax Matrix\tAvailable\tNeed Matrix\n";
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<allocation[i][j]<<" ";
        }
        cout<<"\t";
        for(int j=0;j<col;j++)
        {
            cout<<max[i][j]<<" ";
        }
        cout<<"\t";
        for(int j=0;j<col;j++)
        {
            cout<<available[i][j]<<" ";
        }
        cout<<"\t";
        for(int j=0;j<col;j++)
        {
            cout<<need[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\t\t\t\t";
    for(int j=0;j<col;j++)
    {
        cout<<available[row][j]<<" ";
    } 
    cout<<"\nSafe State : ";
    for(int i=0;i<row;i++)
    {
        cout<<pro[i]<<"->";
    }
    
    return 0;
}